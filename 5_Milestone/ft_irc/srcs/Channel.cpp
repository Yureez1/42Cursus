#include "../inc/Channel.hpp"

Channel::Channel(void) : _clients_n(0), _name(""), _topic(""), _key(""), _limit(0), _mode_i(false), _mode_t(false), _mode_k(false), _mode_l(false) {
    for (int i = 0; i < MAX_CHANNELS; i++)
        this->_clients[i].setFd(-1);
}

Channel::Channel(const Channel &other) { *this = other; }

Channel &Channel::operator=(const Channel &other) {
    if (this != &other) {
        this->_clients_n = other._clients_n;
        for (int i = 0; i < MAX_CHANNELS; i++)
            this->_clients[i] = other._clients[i];
        this->_name = other._name;
        this->_topic = other._topic;
        this->_operators = other._operators;
        this->_invited = other._invited;
        this->_key = other._key;
        this->_limit = other._limit;
        this->_mode_i = other._mode_i;
        this->_mode_t = other._mode_t;
        this->_mode_k = other._mode_k;
        this->_mode_l = other._mode_l;
    }
    return *this;
}

Channel::~Channel(void) {}

std::string Channel::getName(void) { return _name; }

std::string Channel::getTopic(void) { return _topic; }

std::string Channel::getPassword(void) { return _key; }

bool Channel::getInviteOnly(void) { return _mode_i; }

int Channel::getUserLimit(void) { return _limit; }

void Channel::setName(std::string name) { _name = name; }

void Channel::setTopic(std::string topic) { _topic = topic; }

void Channel::setPassword(std::string password) { _key = password; }

void Channel::setInviteOnly(bool v) { _mode_i = v; }

void Channel::setUserLimit(int limit) { _limit = limit; }

int Channel::getClientsNumber(void) { return this->_clients_n; }

Client *Channel::getClient(int i) {
    if (i >= 0 && i < _clients_n)
        return (&_clients[i]);
    return (NULL);
}

std::string Channel::getKey(void) { return _key; }

void Channel::setKey(std::string key) { _key = key; }

bool Channel::isOperator(std::string nick) {
    return (std::find(_operators.begin(), _operators.end(), nick) != _operators.end());
}

void Channel::addOperator(std::string nick) {
    if (!isOperator(nick))
        _operators.push_back(nick);
}

void Channel::removeOperator(std::string nick) {
    std::vector<std::string>::iterator it = std::find(_operators.begin(), _operators.end(), nick);
    if (it != _operators.end())
        _operators.erase(it);
}

void Channel::addInvited(std::string nick) {
    if (!isInvited(nick))
        _invited.push_back(nick);
}

bool Channel::isInvited(std::string nick) {
    return (std::find(_invited.begin(), _invited.end(), nick) != _invited.end());
}

void Channel::addClient(Client client) {
    if (this->_clients_n == 0)
        addOperator(client.getNick());
    this->_clients[this->_clients_n] = client;
    this->_clients_n++;
}

void Channel::rmClient(Client client) {
    for (int i = 0; i < this->_clients_n; i++) {
        if (this->_clients[i].getFd() == client.getFd()) {
            for (int j = i; j < this->_clients_n - 1; j++)
                this->_clients[j] = this->_clients[j + 1];
            this->_clients_n--;
            return;
        }
    }
}

void Channel::broadcast(std::string message, Client &sender) {
    for (int i = 0; i < _clients_n; i++) {
        if (_clients[i].getFd() != sender.getFd())
            _clients[i].ft_send(message);
    }
}

void Channel::setMode(char mode, bool value) {
    switch (mode) {
    case 'i':
        _mode_i = value;
        break;
    case 't':
        _mode_t = value;
        break;
    case 'k':
        _mode_k = value;
        break;
    case 'l':
        _mode_l = value;
        break;
    }
}

bool Channel::getMode(char mode) {
    switch (mode) {
    case 'i':
        return (_mode_i);
    case 't':
        return (_mode_t);
    case 'k':
        return (_mode_k);
    case 'l':
        return (_mode_l);
    }
    return (false);
}

bool Channel::isFull(void) { return _mode_l && _clients_n >= _limit; }

bool Channel::isInChannel(const std::string &nick) {
    for (int i = 0; i < _clients_n; i++) {
        if (_clients[i].getNick() == nick)
            return true;
    }
    return false;
}

const std::vector<std::string> &Channel::getOperators(void) const {
    return _operators;
}

const std::vector<std::string> &Channel::getInvited(void) const {
    return _invited;
}

std::ostream &operator<<(std::ostream &o, Channel &c) {
    o << c.getName() << std::endl;
    return o;
}
