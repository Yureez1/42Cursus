#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>

class Server;

class Client {
private:
    std::string _name;
    std::string _nick;
    int _fd;
    bool _is_authenticated;
    bool _pass_ok;
    std::string _user;
    bool _is_registered;
    bool _waiting_for_cap_end;

    void _join(std::string line, Server &server);
    void _part(std::string line, Server &server);
    void _kick(std::string line, Server &server);
    void _invite(std::string line, Server &server);
    void _topic(std::string line, Server &server);
    void _mode(std::string line, Server &server);
    void _pass(std::string line, Server &server);
    void _nickCmd(std::string line, Server &server);
    void _userCmd(std::string line);
    void _cap(std::string line);
    void _privmsg(std::string line, Server &server);
    void _notice(std::string line, Server &server);
    void _quit(std::string line, Server &server);
    void _ping(std::string line);
    void _who(std::string line, Server &server);
    void _acceptUser(void);

public:
    Client(void);
    Client(const Client &src);
    Client &operator=(const Client &src);
    ~Client(void);

    std::string buffer;
    const static int MAX_CLIENTS = 10;

    std::string getName(void);
    std::string getNick(void);
    std::string getUser(void);
    int getFd(void);

    int _index;
    void setIndex(int index);
    void ft_send(std::string message);
    void setFd(int fd);
    void reset(void);
    bool isPasswordOk() const;
    void setPasswordOk();

    void handleCommand(std::string line, Server &server);
};

std::ostream &operator<<(std::ostream &o, Client &c);

#endif
