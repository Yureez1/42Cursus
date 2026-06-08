# FT_IRC

FT_IRC is a project for [school 42](https://42.fr) that consists of building an IRC (Internet Relay Chat) server in **C++98**, capable of handling multiple clients and channels simultaneously. The server is compatible with the `irssi` reference client and follows the [RFC 2812](https://datatracker.ietf.org/doc/html/rfc2812) standard.

## TABLE OF CONTENTS
1. [General Info](#general-info)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Commands](#commands)
5. [Channel Modes](#channel-modes)
6. [Testing](#testing)
7. [Authors](#authors)

## General Info

- **Language**: C++98
- **Networking**: Non-blocking I/O with `poll()`
- **Protocol**: IRC (RFC 2812)
- **Reference client**: `irssi`
- **Features**:
  - Password-protected server authentication
  - Multiple client connections handled simultaneously
  - Channel creation and management
  - Operator privileges and channel moderation
  - Private messaging between users

## Installation

### Prerequisites

- A C++98 compatible compiler (`c++` / `clang++` / `g++`)
- `make`
- An IRC client (e.g. `irssi`)

### Clone & Build

```bash
git clone https://github.com/Yureez1/ft_irc.git
cd ft_irc
make
```

## Usage

```bash
# Compile the server
make

# Run the server
./ircserv <port> <password>
# Port must be between 1024 and 65535

# Example
./ircserv 6667 mypassword
```

### Connecting with irssi

```bash
# Open a new terminal and run:
irssi -c localhost -p <port> -n <nickname> -w <password>

# Example
irssi -c localhost -p 6667 -n john -w mypassword
```

## Commands for netcat

|  Command |             Description               |           Example           |
|----------|---------------------------------------|-----------------------------|
| `PASS`   | Authenticate with the server password | `PASS mypassword`           |
| `NICK`   | Set or change your nickname           | `NICK john`                 |
| `USER`   | Set your username                     | `USER john`                 |
| `JOIN`   | Join a channel                        | `JOIN #general`             |
| `PART`   | Leave a channel                       | `PART #general`             |
| `PRIVMSG`| Send a message to a channel or user   | `PRIVMSG #general Hello!`   |
| `NOTICE` | Send a notice to a channel or user    | `NOTICE #general Hello!`    |
| `KICK`   | Kick a user from a channel (operator) | `KICK #general john`        |
| `INVITE` | Invite a user to a channel (operator) | `INVITE john #general`      |
| `TOPIC`  | View or set a channel's topic         | `TOPIC #general New topic`  |
| `MODE`   | Change channel or user modes(operator)| `MODE #general +i`          |
| `WHO`    | List users in a channel               | `WHO #general`              |
| `PING`   | Check connection to the server        | `PING server`               |
| `QUIT`   | Disconnect from the server            | `QUIT Goodbye!`             |

## Commands for irssi

|  Command   |             Description               |           Example              |
|------------|---------------------------------------|--------------------------------|
| `/connect` | Authenticate with the server password | `/connect {por} {password}`    |
|      When using connect, nick and user will be automatically filled by irssi        |
| `/nick`    | Change your nickname                  | `/user john`                   |
| `/join`    | Join a channel                        | `/join #general`               |
| `/part`    | Leave a channel                       | `/part #general`               |
| `/msg`     | Send a message to a channel or user   | `/msg #general Hello!`         |
| If you already are in a channel, you can send a message into it without using `/msg`|
| `/notice`  | Send a notice to a channel or user    | `/notice #general Hello!`      |
| `/kick`    | Kick a user from a channel (operator) | `/kick #general john`          |
| `/invite`  | Invite a user to a channel (operator) | `/invite john #general`        |
| `/topic`   | View or set a channel's topic         | `/topic #general New topic`    |
| `/mode`    | Change channel or user modes(operator)| `/mode #general +i`            |
| `/who`     | List users in a channel               | `/who #general`                |
| `/ping`    | Check connection to the server        | `/ping server`                 |
| `/quit`    | Disconnect from the server            | `/quit Goodbye!`               |

## Channel Modes

| Mode | Description                                     |
|------|-------------------------------------------------|
| `+i` | Invite-only channel                             |
| `+t` | Only operators can change the topic             |
| `+k` | Set a channel password                          |
| `+o` | Give/remove operator privileges to a user       |
| `+l` | Set a user limit for the channel                |

  - You can also use `-` instead of `+` to remove existing mode
  - You can also add multiples modes in a single mode command

## Testing

### With irssi

```bash
# Connect to the server
irssi -c localhost -p 6667 -n testuser -w mypassword

# Inside irssi, try the following:
/join #test
/msg #test Hello everyone!
/topic #test My first topic
/invite friend #test
/kick #test spammer
/mode #test +i
/part #test
/quit
```

### With netcat

```bash
# Connect with nc
nc localhost 6667

# Then send raw IRC commands:
PASS mypassword
NICK testuser
USER testuser 0 * :Test User
JOIN #test
PRIVMSG #test :Hello from netcat!
QUIT :Bye
```

## Authors

- Alexandre Bastian (abastian)
- Seyf Dakhlaoui (sdakhlao)
- Julien Banchongphanith (jbanchon)
