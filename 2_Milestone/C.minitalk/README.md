# Minitalk

**Grade: 125/100**

A client-server communication program using UNIX signals (`SIGUSR1` and `SIGUSR2`).

## Overview

The server displays its PID on launch and waits for incoming messages. The client takes the server's PID and a string as arguments, then transmits the message character by character using signals — each bit is encoded as either `SIGUSR1` (0) or `SIGUSR2` (1).

### Key concepts

- **UNIX signals** (`SIGUSR1`, `SIGUSR2`) for inter-process communication
- **Bitwise operations** to encode/decode characters
- Signal handlers with `sigaction`

## Usage

```bash
make

# Terminal 1
./server

# Terminal 2
./client <server_pid> "Hello, World!"
```
