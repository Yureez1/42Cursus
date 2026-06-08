#include "../inc/Server.hpp"

static volatile bool g_running = true;

static void handle_sigint(int) { g_running = false; }

Server::Server(int port, std::string password) : _listen_port(port), _password(password), _clients_n(0), _channels_n(0) {
    if (password.empty()) {
        std::cerr << "Error: Password cannot be empty!" << std::endl;
        return;
    }
}

Server::Server(void) : _listen_port(6667), _password("password"), _clients_n(0), _channels_n(0) {}

Server::Server(const Server &other) { *this = other; }

Server &Server::operator=(const Server &other) {
    if (this != &other) {
        _listen_port = other._listen_port;
        _password = other._password;
    }
    return *this;
}

Server::~Server(void) {}

std::string Server::getPassword(void) { return _password; }

int Server::_makeListenSocket(int port) {
    struct sockaddr_in myaddr;
    memset(&myaddr, 0, sizeof(myaddr));

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(port);
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
        throw(std::runtime_error("Failed to create socket"));
    int en = 1;
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &en, sizeof(en)) == -1)
        throw(std::runtime_error("Failed to set option (SO_REUSEADDR) on socket"));
    if (fcntl(socketfd, F_SETFL, O_NONBLOCK) == -1)
        throw(std::runtime_error("Failed to set option (O_NONBLOCK) on socket"));
    if (bind(socketfd, (struct sockaddr *)&myaddr, sizeof(myaddr)) == -1) {
        close(socketfd);
        throw(std::runtime_error("Failed to bind socket"));
    }
    if (listen(socketfd, Client::MAX_CLIENTS) == -1) {
        close(socketfd);
        throw(std::runtime_error("listen() failed"));
    }
    return socketfd;
}

void Server::_acceptNewClients(int listen_fd) {
    struct sockaddr_in client_addr;
    while (true) {
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                break;
            } else {
                std::cout << "Client fd failed" << errno << std::endl;
                continue;
            }
        }
        if (fcntl(client_fd, F_SETFL, O_NONBLOCK)) {
            throw(std::runtime_error("Failed to set option (O_NONBLOCK) on client_fd"));
        }
        if (_clients_n < Client::MAX_CLIENTS) {
            _pfds[_clients_n + 2].fd = client_fd;
            _pfds[_clients_n + 2].events = POLLIN;
            _pfds[_clients_n + 2].revents = 0;
            _clients[_clients_n].reset();
            _clients[_clients_n].setFd(client_fd);
            _clients[_clients_n].buffer = "";
            _clients[_clients_n].setIndex(_clients_n + 1);
            std::cout << _clients_n + 1 << " connected" << std::endl;
            _clients_n++;
        } else {
            std::cout << "Max client reached" << std::endl;
            close(client_fd);
        }
    }
}

void Server::_handleStdin(void) {
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cout << "EOF Detected, closing socket" << std::endl;
        g_running = false;
        return;
    }
    if (line == "debug" || line == "DEBUG") {
        std::cout << "=== DEBUG ===" << std::endl;
        std::cout << "Client connected: " << _pfds[_clients_n].fd;
        for (int i = 2; i < _clients_n + 2; i++) {
            if (_clients[i].getFd() != -1)
                std::cout << "Client fd: " << _clients[i].getFd() << "Nick= " << _clients[i].getNick() << "Name= " << _clients[i].getName() << std::endl;
        }
        std::cout << "Channels: " << _channels_n << std::endl;
        for (int i = 0; i < _channels_n; i++)
            std::cout << _channels[i] << std::endl;
        std::cout << "----------------" << std::endl;
    }
    if (line == "exit" || line == "EXIT") {
        g_running = false;
    } else
        std::cout << "Echo: " << line << std::endl;
}

void Server::start(void) {
    signal(SIGINT, handle_sigint);
    int listen_fd = _makeListenSocket(_listen_port);
    if (listen_fd == -1) {
        throw(std::runtime_error("Socket failed"));
        return;
    }
    // Ca sert a initiliaser les fd
    _pfds[0].fd = listen_fd;  // Socket a ecouter
    _pfds[0].events = POLLIN; // Des donnees en attente de lecture
    _pfds[0].revents = 0;     // Des donnees detectees
    _pfds[1].fd = STDIN_FILENO;
    _pfds[1].events = POLLIN;
    while (g_running) {
        if ((poll(_pfds, _clients_n + 2, -1) == -1)) {
            if (errno == EINTR)
                continue;
            throw(std::runtime_error("Poll() failed"));
        }
        if (_pfds[0].revents & POLLIN)
            _acceptNewClients(listen_fd);
        if (_pfds[1].revents & POLLIN)
            _handleStdin();
        for (int i = 2; i < _clients_n + 2; ++i)
            _handleClientIO(i);
        _compactFds();
    }
	for (int i = 0; i < _clients_n; i++) {
        if (_clients[i].getFd() > 0)
            close(_clients[i].getFd());
    }
	close(listen_fd);
}

void Server::_handleClientIO(int i) {
    int fd = _pfds[i].fd;
    if (fd < 0)
        return;
    if (_pfds[i].revents & (POLLIN | POLLERR | POLLHUP)) {
        char tmp_buffer[512];
        int bytes = recv(fd, tmp_buffer, 511, 0);
        if (bytes <= 0) {
            std::cout << "Client disconnected: " << std::endl;
            _removeClientFromChannels(fd);
            close(fd);
            _pfds[i].fd = -1;
            _clients[i - 2].reset();
        } else {
            tmp_buffer[bytes] = 0;
            Client &client = _clients[i - 2];
            client.buffer += tmp_buffer;
            size_t pos;
            while ((pos = client.buffer.find("\n")) != std::string::npos) {
                std::string line = client.buffer.substr(0, pos);
                client.buffer.erase(0, pos + 1);
                if (!line.empty() && line[line.size() - 1] == '\r')
                    line.erase(line.size() - 1);
                if (!line.empty())
                    client.handleCommand(line, *this);
                if (client.getFd() < 0)
                    break;
            }
        }
    }
}

void Server::disconnect(int fd, std::string error) {
    for (int i = 2; i < _clients_n + 2; i++) {
        if (_pfds[i].fd == fd) {
            if (!error.empty()) {
                std::string message = "ERROR :" + error + "\r\n";
                send(fd, message.c_str(), message.size(), 0);
            }
            std::cout << i - 1 << " disconnected" << std::endl;
            _removeClientFromChannels(fd);
            close(fd);
            _pfds[i].fd = -1;
            _clients[i - 2].reset();
            return;
        }
    }
}

void Server::quitDisconnect(int fd, std::string message) {
    Client *client = getClientByFd(fd);
    if (!client)
        return;
    std::string quit_msg = ":" + client->getNick() + "!" + client->getUser() + "@localhost QUIT";
    if (!message.empty())
        quit_msg += " :" + message;
    quit_msg += "\r\n";
    for (int i = 0; i < _channels_n; i++) {
        if (_channels[i].isInChannel(client->getNick()))
            _channels[i].broadcast(quit_msg, *client);
    }
    std::cout << client->getNick() << " disconnected" << std::endl;
    _removeClientFromChannels(fd);
    close(fd);
    for (int i = 2; i < _clients_n + 2; i++) {
        if (_pfds[i].fd == fd) {
            _pfds[i].fd = -1;
            _clients[i - 2].reset();
            break;
        }
    }
}

void Server::_removeClientFromChannels(int fd) {
    for (int i = 0; i < _channels_n; i++) {
        Client c;
        c.setFd(fd);
        _channels[i].rmClient(c);
        if (_channels[i].getClientsNumber() == 0) {
            removeChannel(_channels[i].getName());
            i--;
        }
    }
}

Client *Server::getClientByNick(std::string nick) {
    for (int i = 0; i < _clients_n; i++) {
        if (_clients[i].getFd() != -1 && _clients[i].getNick() == nick)
            return &_clients[i];
    }
    return NULL;
}

Client *Server::getClientByFd(int fd) {
    for (int i = 0; i < _clients_n; i++) {
        if (_clients[i].getFd() == fd)
            return &_clients[i];
    }
    return NULL;
}

bool Server::addChannel(Channel c) {
    if (this->_channels_n >= Channel::MAX_CHANNELS)
        return (false);
    this->_channels[this->_channels_n] = c;
    this->_channels_n++;
    return (true);
}

void Server::removeChannel(std::string name) {
    for (int i = 0; i < this->_channels_n; i++) {
        if (this->_channels[i].getName() == name) {
            for (int j = i; j < this->_channels_n - 1; j++)
                this->_channels[j] = this->_channels[j + 1];
            this->_channels_n--;
            return;
        }
    }
}

Channel *Server::getChannel(std::string name) {
    for (int i = 0; i < this->_channels_n; i++) {
        if (this->_channels[i].getName() == name)
            return (&this->_channels[i]);
    }
    return (NULL);
}

void Server::_compactFds() {
    int newFds = 2;
    int newClientFds = _clients_n + 2;
    for (int i = 2; i < newClientFds; i++) {
        if (_pfds[i].fd != -1) {
            if (newFds != i) {
                _pfds[newFds] = _pfds[i];
                _clients[newFds - 2] = _clients[i - 2];
                _clients[newFds - 2].setIndex(newFds - 1);
            }
            newFds++;
        }
    }
    _clients_n = newFds - 2;
}
