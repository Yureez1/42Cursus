#include "../inc/Client.hpp"
#include "../inc/Server.hpp"
#include <string>

Client::Client(void) : _name(""), _nick(""), _fd(0), _is_authenticated(false), _pass_ok(false), _user(""), _is_registered(false), _waiting_for_cap_end(false), _index(0) {}

Client::Client(const Client &other) { *this = other; }

Client &Client::operator=(const Client &src) {
    if (this != &src) {
        _name = src._name;
        _nick = src._nick;
        _fd = src._fd;
        _is_authenticated = src._is_authenticated;
        _pass_ok = src._pass_ok;
        _user = src._user;
        _is_registered = src._is_registered;
        _waiting_for_cap_end = src._waiting_for_cap_end;
        buffer = src.buffer;
    }
    return *this;
}

Client::~Client(void) {}

std::string Client::getName(void) { return _name; }

std::string Client::getNick(void) { return _nick; }

std::string Client::getUser(void) { return _user; }

int Client::getFd(void) { return _fd; }

void Client::setFd(int fd) { _fd = fd; }

void Client::setIndex(int index) { _index = index; }

bool Client::isPasswordOk() const { return (this->_pass_ok); }

void Client::setPasswordOk() { _pass_ok = true; }

void Client::handleCommand(std::string line, Server &server) {
    size_t space = line.find(' ');
    std::string command = (space == std::string::npos) ? line : line.substr(0, space);
    if (server.getPassword().empty())
        setPasswordOk();
    if (command == "CAP") {
        _cap(line);
        return;
    }
    if (command == "PASS") {
        if (isPasswordOk()) {
            std::string current = _nick.empty() ? "*" : _nick;
            ft_send(":ircserv 462 " + current + " :You may not reregister\r\n");
        } else {
            _pass(line, server);
            if (_is_authenticated)
                setPasswordOk();
        }
        return;
    }
    if (command == "NICK") {
        _nickCmd(line, server);
        return;
    }
    if (command == "USER" || command == "userhost") {
        _userCmd(line);
        return;
    }
    if (!_is_registered) {
        std::string current = _nick.empty() ? "*" : _nick;
        if (!command.empty())
            ft_send(":ircserv 451 " + current + " :You have not registered\r\n");
        return;
    }
    if (command == "JOIN")
        _join(line, server);
    else if (command == "PART")
        _part(line, server);
    else if (command == "KICK")
        _kick(line, server);
    else if (command == "INVITE")
        _invite(line, server);
    else if (command == "TOPIC")
        _topic(line, server);
    else if (command == "MODE")
        _mode(line, server);
    else if (command == "PRIVMSG")
        _privmsg(line, server);
    else if (command == "NOTICE")
        _notice(line, server);
    else if (command == "QUIT")
        _quit(line, server);
    else if (command == "PING")
        _ping(line);
    else if (command == "WHO")
        _who(line, server);
    else
        ft_send(":ircserv 421 " + _nick + " " + command + " :Unknown command\r\n");
}

void Client::ft_send(std::string message) {
    std::string log_message = message;
    if (!log_message.empty() && log_message[log_message.size() - 1] == '\n')
        log_message.erase(log_message.size() - 1);
    if (!log_message.empty() && log_message[log_message.size() - 1] == '\r')
        log_message.erase(log_message.size() - 1);
    std::cout << _index << "->[" << log_message << "]" << std::endl;
    send(_fd, message.c_str(), message.size(), 0);
}

void Client::_pass(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 461 * PASS :Not enough parameters\r\n");
        return;
    }
    std::string password = line.substr(first_space + 1);
    if (password == server.getPassword())
        _is_authenticated = true;
    else {
        ft_send(":ircserv 464 * :Password incorrect\r\n");
        server.disconnect(getFd(), "");
    }
}

void Client::_userCmd(std::string line) {
    std::string current = _nick.empty() ? "*" : _nick;
    if (!_user.empty()) {
        ft_send(":ircserv 462 " + current + " :You may not reregister\r\n");
        return;
    }
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 461 " + current + " USER :Not enough parameters\r\n");
        return;
    }
    std::string params = line.substr(first_space + 1);
    size_t second_space = params.find(' ');
    if (second_space == std::string::npos)
        _user = params;
    else
        _user = params.substr(0, second_space);

    size_t start = _user.find_first_not_of(' ');
    size_t end = _user.find_last_not_of(' ');
    if (start == std::string::npos || end == std::string::npos) {
        ft_send(":ircserv 461 " + current + " USER :Not enough parameters\r\n");
        return;
    }

    size_t colon_pos = line.find(':');
    if (colon_pos != std::string::npos) {
        std::string real_name = line.substr(colon_pos + 1);
        _name = real_name;
    }
    _acceptUser();
}

void Client::_nickCmd(std::string line, Server &server) {
    std::string current = _nick.empty() ? "*" : _nick;
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 431 " + current + " :No nickname given\r\n");
        return;
    }
    std::string nick = line.substr(first_space + 1);
    size_t start = nick.find_first_not_of(' ');
    size_t end = nick.find_last_not_of(' ');
    if (start == std::string::npos || end == std::string::npos) {
        ft_send(":ircserv 431 " + current + " :No nickname given\r\n");
        return;
    }
    nick = nick.substr(start, end - start + 1);
    if (server.getClientByNick(nick)) {
        ft_send(":ircserv 433 " + current + " " + nick + " :Nickname is already in use\r\n");
        return;
    }
    _nick = nick;
    _acceptUser();
}

void Client::_cap(std::string line) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos)
        return;
    std::string subcommand = line.substr(first_space + 1);
    size_t second_space = subcommand.find(' ');
    if (second_space != std::string::npos)
        subcommand = subcommand.substr(0, second_space);

    if (subcommand == "LS") {
        _waiting_for_cap_end = true;
        ft_send(":ircserv CAP * LS :\r\n");
    } else if (subcommand == "REQ") {
        ft_send(":ircserv CAP * NAK :\r\n");
    } else if (subcommand == "END") {
        _waiting_for_cap_end = false;
        _acceptUser();
    }
}

void Client::_join(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 461 " + _nick + " JOIN :Not enough parameters\r\n");
        return;
    }
    size_t second_space = line.find(' ', first_space + 1);
    std::string channel_name;
    std::string key;
    if (second_space == std::string::npos) {
        channel_name = line.substr(first_space + 1);
    } else {
        channel_name = line.substr(first_space + 1, second_space - (first_space + 1));
        key = line.substr(second_space + 1);
    }

    if (channel_name.empty() || channel_name[0] != '#') {
        ft_send(":ircserv 403 " + _nick + " " + channel_name + " :No such channel\r\n");
        return;
    }

    Channel *channel = server.getChannel(channel_name);
    if (!channel) {
        Channel new_channel;
        new_channel.setName(channel_name);
        new_channel.addClient(*this);
        server.addChannel(new_channel);
        channel = server.getChannel(channel_name);
        ft_send(":" + _nick + "!" + _user + "@localhost JOIN " + channel_name + "\r\n");
        std::string topic = channel->getTopic();
        if (!topic.empty())
            ft_send(":ircserv 332 " + _nick + " " + channel_name + " :" + topic + "\r\n");
        else
            ft_send(":ircserv 331 " + _nick + " " + channel_name + " :No topic is set\r\n");
        std::string names_reply = ":ircserv 353 " + _nick + " = " + channel_name + " :";
        for (int i = 0; i < channel->getClientsNumber(); i++) {
            Client *c = channel->getClient(i);
            if (channel->isOperator(c->getNick()))
                names_reply += "@";
            names_reply += c->getNick() + " ";
        }
        names_reply += "\r\n";
        ft_send(names_reply);
        ft_send(":ircserv 366 " + _nick + " " + channel_name + " :End of /NAMES list\r\n");
        std::cout << "Channel " << channel_name << " created" << std::endl;
    } else {
        if (channel->isInChannel(_nick))
            return;
        if (channel->getInviteOnly() && !channel->isInvited(_nick)) {
            ft_send(":ircserv 473 " + _nick + " " + channel_name + " :Cannot join channel (+i)\r\n");
            return;
        }
        if (channel->getMode('k')) {
            if (key != channel->getKey()) {
                ft_send(":ircserv 475 " + _nick + " " + channel_name + " :Cannot join channel (+k)\r\n");
                return;
            }
        }
        if (channel->isFull()) {
            ft_send(":ircserv 471 " + _nick + " " + channel_name + " :Cannot join channel (+l)\r\n");
            return;
        }
        channel->addClient(*this);
        std::string join_msg = ":" + _nick + "!" + _user + "@localhost JOIN " + channel_name + "\r\n";
        channel->broadcast(join_msg, *this);
        ft_send(join_msg);
        std::string topic = channel->getTopic();
        if (!topic.empty())
            ft_send(":ircserv 332 " + _nick + " " + channel_name + " :" + topic + "\r\n");
        else
            ft_send(":ircserv 331 " + _nick + " " + channel_name + " :No topic is set\r\n");
        std::string names_reply = ":ircserv 353 " + _nick + " = " + channel_name + " :";
        for (int i = 0; i < channel->getClientsNumber(); i++) {
            Client *c = channel->getClient(i);
            if (channel->isOperator(c->getNick()))
                names_reply += "@";
            names_reply += c->getNick() + " ";
        }
        names_reply += "\r\n";
        ft_send(names_reply);
        ft_send(":ircserv 366 " + _nick + " " + channel_name + " :End of /NAMES list\r\n");
    }
}

void Client::_part(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 461 " + _nick + " PART :Not enough parameters\r\n");
        return;
    }
    std::string params = line.substr(first_space + 1);
    size_t colon_pos = params.find(':');
    std::string channels_str = (colon_pos == std::string::npos) ? params : params.substr(0, colon_pos);
    std::string reason = (colon_pos == std::string::npos) ? "" : params.substr(colon_pos + 1);

    if (colon_pos != std::string::npos && !channels_str.empty() && channels_str[channels_str.size() - 1] == ' ')
        channels_str.erase(channels_str.size() - 1);

    size_t pos = 0;
    while ((pos = channels_str.find(',')) != std::string::npos) {
        std::string channel_name = channels_str.substr(0, pos);
        Channel *channel = server.getChannel(channel_name);
        if (channel) {
            if (!channel->isInChannel(_nick))
                ft_send(":ircserv 442 " + _nick + " " + channel_name + " :You're not on that channel\r\n");
            else {
                std::string part_msg = ":" + _nick + "!" + _user + "@localhost PART " + channel_name;
                if (!reason.empty())
                    part_msg += " :" + reason;
                part_msg += "\r\n";
                channel->broadcast(part_msg, *this);
                ft_send(part_msg);
                channel->rmClient(*this);
                if (channel->getClientsNumber() == 0) {
                    server.removeChannel(channel_name);
                    std::cout << "Channel " << channel_name << " removed" << std::endl;
                }
            }
        } else
            ft_send(":ircserv 403 " + _nick + " " + channel_name + " :No such channel\r\n");
        channels_str.erase(0, pos + 1);
    }
    if (!channels_str.empty()) {
        std::string channel_name = channels_str;
        Channel *channel = server.getChannel(channel_name);
        if (channel) {
            if (!channel->isInChannel(_nick)) {
                ft_send(":ircserv 442 " + _nick + " " + channel_name + " :You're not on that channel\r\n");
            } else {
                std::string part_msg = ":" + _nick + "!" + _user + "@localhost PART " + channel_name;
                if (!reason.empty())
                    part_msg += " :" + reason;
                part_msg += "\r\n";
                channel->broadcast(part_msg, *this);
                ft_send(part_msg);
                channel->rmClient(*this);
                if (channel->getClientsNumber() == 0) {
                    server.removeChannel(channel_name);
                    std::cout << "Channel " << channel_name << " removed" << std::endl;
                }
            }
        } else
            ft_send(":ircserv 403 " + _nick + " " + channel_name + " :No such channel\r\n");
    }
}

void Client::_kick(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 461 " + _nick + " KICK :Not enough parameters\r\n");
        return;
    }
    std::string params = line.substr(first_space + 1);
    size_t second_space = params.find(' ');
    if (second_space == std::string::npos) {
        ft_send(":ircserv 461 " + _nick + " KICK :Not enough parameters\r\n");
        return;
    }
    std::string channel_name = params.substr(0, second_space);
    std::string user_reason = params.substr(second_space + 1);
    std::string target_nick = user_reason;
    std::string reason = "";
    size_t third_space = user_reason.find(' ');
    if (third_space != std::string::npos) {
        target_nick = user_reason.substr(0, third_space);
        reason = user_reason.substr(third_space + 1);
        if (!reason.empty() && reason[0] == ':')
            reason = reason.substr(1);
    }

    Channel *channel = server.getChannel(channel_name);
    if (!channel) {
        ft_send(":ircserv 403 " + _nick + " " + channel_name + " :No such channel\r\n");
        return;
    }
    if (!channel->isOperator(_nick)) {
        ft_send(":ircserv 482 " + _nick + " " + channel_name + " :You're not channel operator\r\n");
        return;
    }
    Client *target = server.getClientByNick(target_nick);
    if (!target) {
        ft_send(":ircserv 401 " + _nick + " " + target_nick + " :No such nick/channel\r\n");
        return;
    }
    if (!channel->isInChannel(target_nick)) {
        ft_send(":ircserv 441 " + _nick + " " + target_nick + " " + channel_name + " :They aren't on that channel\r\n");
        return;
    }
    std::string kick_msg = ":" + _nick + "!" + _user + "@localhost KICK " + channel_name + " " + target_nick + " :" + reason + "\r\n";
    channel->rmClient(*target);
    channel->broadcast(kick_msg, *this);
    ft_send(kick_msg);
    target->ft_send(kick_msg);
    if (channel->getClientsNumber() == 0)
        server.removeChannel(channel_name);
}

void Client::_invite(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 461 " + _nick + " INVITE :Not enough parameters\r\n");
        return;
    }
    std::string params = line.substr(first_space + 1);
    size_t second_space = params.find(' ');
    if (second_space == std::string::npos) {
        ft_send(":ircserv 461 " + _nick + " INVITE :Not enough parameters\r\n");
        return;
    }
    std::string target_nick = params.substr(0, second_space);
    std::string channel_name = params.substr(second_space + 1);

    Channel *channel = server.getChannel(channel_name);
    if (!channel) {
        ft_send(":ircserv 403 " + _nick + " " + channel_name + " :No such channel\r\n");
        return;
    }
    if (!channel->isInChannel(_nick)) {
        ft_send(":ircserv 442 " + _nick + " " + channel_name + " :You're not on that channel\r\n");
        return;
    }
    if (channel->getInviteOnly() && !channel->isOperator(_nick)) {
        ft_send(":ircserv 482 " + _nick + " " + channel_name + " :You're not channel operator\r\n");
        return;
    }
    Client *target = server.getClientByNick(target_nick);
    if (!target) {
        ft_send(":ircserv 401 " + _nick + " " + target_nick + " :No such nick/channel\r\n");
        return;
    }
    if (channel->isInChannel(target_nick)) {
        ft_send(":ircserv 443 " + _nick + " " + target_nick + " " + channel_name + " :is already on channel\r\n");
        return;
    }
    channel->addInvited(target_nick);
    ft_send(":ircserv 341 " + _nick + " " + target_nick + " " + channel_name + "\r\n");
    target->ft_send(":" + _nick + "!" + _user + "@localhost INVITE " + target_nick + " " + channel_name + "\r\n");
}

void Client::_topic(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 461 " + _nick + " TOPIC :Not enough parameters\r\n");
        return;
    }
    std::string params = line.substr(first_space + 1);
    std::string channel_name;
    std::string topic = "";
    size_t second_space = params.find(' ');
    if (second_space != std::string::npos) {
        channel_name = params.substr(0, second_space);
        topic = params.substr(second_space + 1);
        if (!topic.empty() && topic[0] == ':')
            topic = topic.substr(1);
    } else {
        channel_name = params;
    }
    Channel *channel = server.getChannel(channel_name);
    if (!channel) {
        ft_send(":ircserv 403 " + _nick + " " + channel_name + " :No such channel\r\n");
        return;
    }
    if (!channel->isInChannel(_nick)) {
        ft_send(":ircserv 442 " + _nick + " " + channel_name + " :You're not on that channel\r\n");
        return;
    }
    if (topic.empty()) {
        std::string current_topic = channel->getTopic();
        if (current_topic.empty())
            ft_send(":ircserv 331 " + _nick + " " + channel_name + " :No topic is set\r\n");
        else
            ft_send(":ircserv 332 " + _nick + " " + channel_name + " :" + current_topic + "\r\n");
    } else {
        if (channel->getMode('t') && !channel->isOperator(_nick)) {
            ft_send(":ircserv 482 " + _nick + " " + channel_name + " :You're not channel operator\r\n");
            return;
        }
        channel->setTopic(topic);
        std::string topic_msg = ":" + _nick + "!" + _user + "@localhost TOPIC " + channel_name + " :" + topic + "\r\n";
        channel->broadcast(topic_msg, *this);
        ft_send(topic_msg);
    }
}

void Client::_mode(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 461 " + _nick + " MODE :Not enough parameters\r\n");
        return;
    }
    std::string params = line.substr(first_space + 1);
    size_t second_space = params.find(' ');
    std::string channel_name = params;
    std::string modes = "";
    std::string args = "";
    if (second_space != std::string::npos) {
        channel_name = params.substr(0, second_space);
        std::string tmp = params.substr(second_space + 1);
        size_t third_space = tmp.find(' ');
        if (third_space != std::string::npos) {
            modes = tmp.substr(0, third_space);
            args = tmp.substr(third_space + 1);
        } else
            modes = tmp;
    }

    if (channel_name.empty() || channel_name[0] != '#') {
        if (modes.empty()) {
            ft_send(":ircserv 221 " + _nick + " +\r\n");
        }
        return;
    }

    Channel *channel = server.getChannel(channel_name);
    if (!channel) {
        ft_send(":ircserv 403 " + _nick + " " + channel_name + " :No such channel\r\n");
        return;
    }
    if (modes.empty()) {
        std::string mode_str = "+";
        std::string mode_params = "";
        if (channel->getMode('i'))
            mode_str += "i";
        if (channel->getMode('t'))
            mode_str += "t";
        if (channel->getMode('k')) {
            mode_str += "k";
            mode_params += " " + channel->getKey();
        }
        if (channel->getMode('l')) {
            mode_str += "l";
            std::stringstream ss;
            ss << channel->getUserLimit();
            mode_params += " " + ss.str();
        }
        ft_send(":ircserv 324 " + _nick + " " + channel_name + " " + mode_str + mode_params + "\r\n");
        return;
    }
    if (!channel->isOperator(_nick)) {
        ft_send(":ircserv 482 " + _nick + " " + channel_name + " :You're not channel operator\r\n");
        return;
    }

    bool add = true;
    size_t arg_pos = 0;
    std::string applied_modes = "";
    std::string applied_args = "";
    bool current_sign_printed = false;
    bool last_was_add = true;

    for (size_t i = 0; i < modes.size(); i++) {
        char c = modes[i];
        if (c == '+') {
            add = true;
        } else if (c == '-') {
            add = false;
        } else if (c == 'i') {
            channel->setMode('i', add);
            if (!current_sign_printed || last_was_add != add) {
                applied_modes += add ? "+" : "-";
                current_sign_printed = true;
                last_was_add = add;
            }
            applied_modes += "i";
        } else if (c == 't') {
            channel->setMode('t', add);
            if (!current_sign_printed || last_was_add != add) {
                applied_modes += add ? "+" : "-";
                current_sign_printed = true;
                last_was_add = add;
            }
            applied_modes += "t";
        } else if (c == 'k') {
            if (add) {
                std::string key = "";
                size_t next_space = args.find(' ', arg_pos);
                if (next_space == std::string::npos)
                    key = args.substr(arg_pos);
                else {
                    key = args.substr(arg_pos, next_space - arg_pos);
                    arg_pos = next_space + 1;
                }
                if (key.empty()) {
                    ft_send(":ircserv 461 " + _nick + " MODE :Not enough parameters\r\n");
                    return;
                }
                channel->setKey(key);
                channel->setMode('k', true);
                if (!current_sign_printed || last_was_add != add) {
                    applied_modes += "+";
                    current_sign_printed = true;
                    last_was_add = add;
                }
                applied_modes += "k";
                applied_args += " " + key;
            } else {
                channel->setKey("");
                channel->setMode('k', false);
                if (!current_sign_printed || last_was_add != add) {
                    applied_modes += "-";
                    current_sign_printed = true;
                    last_was_add = add;
                }
                applied_modes += "k";
            }
        } else if (c == 'o') {
            std::string target = "";
            size_t next_space = args.find(' ', arg_pos);
            if (next_space == std::string::npos)
                target = args.substr(arg_pos);
            else {
                target = args.substr(arg_pos, next_space - arg_pos);
                arg_pos = next_space + 1;
            }
            if (target.empty()) {
                ft_send(":ircserv 461 " + _nick + " MODE :Not enough parameters\r\n");
                return;
            }
            if (add)
                channel->addOperator(target);
            else
                channel->removeOperator(target);
            if (!current_sign_printed || last_was_add != add) {
                applied_modes += add ? "+" : "-";
                current_sign_printed = true;
                last_was_add = add;
            }
            applied_modes += "o";
            applied_args += " " + target;
        } else if (c == 'l') {
            if (add) {
                std::string limit_str = "";
                size_t next_space = args.find(' ', arg_pos);
                if (next_space == std::string::npos)
                    limit_str = args.substr(arg_pos);
                else {
                    limit_str = args.substr(arg_pos, next_space - arg_pos);
                    arg_pos = next_space + 1;
                }
                if (limit_str.empty()) {
                    ft_send(":ircserv 461 " + _nick + " MODE :Not enough parameters\r\n");
                    return;
                }
                channel->setUserLimit(std::atoi(limit_str.c_str()));
                channel->setMode('l', true);
                if (!current_sign_printed || last_was_add != add) {
                    applied_modes += "+";
                    current_sign_printed = true;
                    last_was_add = add;
                }
                applied_modes += "l";
                applied_args += " " + limit_str;
            } else {
                channel->setUserLimit(0);
                channel->setMode('l', false);
                if (!current_sign_printed || last_was_add != add) {
                    applied_modes += "-";
                    current_sign_printed = true;
                    last_was_add = add;
                }
                applied_modes += "l";
            }
        }
    }
    if (!applied_modes.empty()) {
        std::string mode_msg = ":" + _nick + "!" + _user + "@localhost MODE " + channel_name + " " + applied_modes + applied_args + "\r\n";
        channel->broadcast(mode_msg, *this);
        ft_send(mode_msg);
    }
}

void Client::_acceptUser(void) {
    if (!_nick.empty() && !_user.empty() && !_is_registered && !_waiting_for_cap_end && _pass_ok) {
        _is_registered = true;
        std::string reply;
        reply = ":ircserv 001 " + _nick + " :Welcome to the Internet Relay Network " + _nick + "!" + _user + "@localhost\r\n";
        ft_send(reply);
        reply = ":ircserv 002 " + _nick + " :Your host is ircserv, running version 1.0\r\n";
        ft_send(reply);
        reply = ":ircserv 003 " + _nick + " :This server was created today\r\n";
        ft_send(reply);
        reply = ":ircserv 004 " + _nick + " ircserv 1.0 - itkol\r\n";
        ft_send(reply);
    }
}

void Client::_quit(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    std::string message = "";
    if (first_space != std::string::npos) {
        message = line.substr(first_space + 1);
        if (!message.empty() && message[0] == ':')
            message = message.substr(1);
    }
    server.quitDisconnect(getFd(), message);
}

void Client::_ping(std::string line) {
    size_t first_space = line.find(' ');
    std::string token = "";
    if (first_space != std::string::npos)
        token = line.substr(first_space + 1);
    if (token.empty()) {
        ft_send(":ircserv 409 " + _nick + " :No origin specified\r\n");
        return;
    }
    ft_send(":ircserv PONG ircserv :" + token + "\r\n");
}

void Client::_privmsg(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos) {
        ft_send(":ircserv 411 " + _nick + " :No recipient given (PRIVMSG)\r\n");
        return;
    }
    std::string params = line.substr(first_space + 1);
    size_t second_space = params.find(' ');
    if (second_space == std::string::npos) {
        ft_send(":ircserv 412 " + _nick + " :No text to send\r\n");
        return;
    }
    std::string target = params.substr(0, second_space);
    std::string message = params.substr(second_space + 1);

    if (message.size() > 0 && message[0] == ':')
        message = message.substr(1);

    std::string full_message = ":" + _nick + "!" + _user + "@localhost PRIVMSG " + target + " :" + message + "\r\n";

    if (target[0] == '#') {
        Channel *channel = server.getChannel(target);
        if (channel && channel->isInChannel(this->_nick))
            channel->broadcast(full_message, *this);
        else if (channel)
            ft_send(":ircserv 404 " + _nick + " " + channel->getName() + " :Cannot send to channel\r\n");
        else
            ft_send(":ircserv 401 " + _nick + " " + target + " :No such nick/channel\r\n");
    } else {
        Client *recipient = server.getClientByNick(target);
        if (recipient)
            recipient->ft_send(full_message);
        else
            ft_send(":ircserv 401 " + _nick + " " + target + " :No such nick/channel\r\n");
    }
}

void Client::_notice(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos)
        return;
    std::string params = line.substr(first_space + 1);
    size_t second_space = params.find(' ');
    if (second_space == std::string::npos)
        return;
    std::string target = params.substr(0, second_space);
    std::string message = params.substr(second_space + 1);

    if (message.size() > 0 && message[0] == ':')
        message = message.substr(1);

    std::string full_message = ":" + _nick + "!" + _user + "@localhost NOTICE " + target + " :" + message + "\r\n";

    if (target[0] == '#') {
        Channel *channel = server.getChannel(target);
        if (channel && channel->isInChannel(this->_nick))
            channel->broadcast(full_message, *this);
    } else {
        Client *recipient = server.getClientByNick(target);
        if (recipient)
            recipient->ft_send(full_message);
    }
}

void Client::reset(void) {
    _name = "";
    _nick = "";
    _fd = -1;
    _is_authenticated = false;
    _pass_ok = false;
    _user = "";
    _is_registered = false;
    _waiting_for_cap_end = false;
    buffer = "";
    _index = 0;
}

void Client::_who(std::string line, Server &server) {
    size_t first_space = line.find(' ');
    if (first_space == std::string::npos)
        return;
    std::string target = line.substr(first_space + 1);
    if (target.empty())
        return;
    if (target[0] == '#') {
        Channel *channel = server.getChannel(target);
        if (channel) {
            for (int i = 0; i < channel->getClientsNumber(); i++) {
                Client *c = channel->getClient(i);
                std::string prefix = channel->isOperator(c->getNick()) ? "@" : "";
                ft_send(":ircserv 352 " + _nick + " " + target + " " + c->getUser() +
                        " localhost ircserv " + c->getNick() + " H" + prefix + " :0 " +
                        c->getName() + "\r\n");
            }
        }
    }
    ft_send(":ircserv 315 " + _nick + " " + target + " :End of /WHO list\r\n");
}
