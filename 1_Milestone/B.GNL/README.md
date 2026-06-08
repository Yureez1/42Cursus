# get_next_line

**Grade: 125/100**

A function that reads a line from a file descriptor, one at a time. Repeated calls return successive lines from a file, stream, or stdin.

## Overview

The function `get_next_line(int fd)` returns the next line from the given file descriptor, including the terminating `\n` (except at EOF). It uses a static variable to keep track of the reading position between calls.

### Key concepts

- **Static variables** to persist state across function calls
- **Dynamic memory allocation** with buffer management
- **File I/O** using the `read` system call
- Configurable `BUFFER_SIZE` at compile time

### Bonus

The bonus version handles multiple file descriptors simultaneously — you can alternate between different FDs without losing track of each one's reading position.

## Usage

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
