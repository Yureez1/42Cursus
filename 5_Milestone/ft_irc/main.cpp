#include "inc/Server.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: ./ircserv <port> <password>" << std::endl;
        return 1;
    }
    std::string port_str = argv[1];
    for (size_t i = 0; i < port_str.size(); i++) {
        if (port_str[i] < '0' || port_str[i] > '9') {
            std::cerr << "Error: port must be a number" << std::endl;
            return 1;
        }
    }
    int port = atoi(argv[1]);
    if (port < 1024 || port > 6667) {
        std::cerr << "Error: port must be between 1024 and 6667" << std::endl;
        return 1;
    }
    std::string password = argv[2];
    if (password.empty()) {
        std::cerr << "Error: password cannot be empty" << std::endl;
        return 1;
    }
    std::cout << "Server is running" << std::endl;
    std::cout << "port: " << port << std::endl;
    Server srv(port, password);
    srv.start();
    return 0;
}
