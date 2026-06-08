# Minishell

**Grade: 100/100**

A simplified bash shell implementation, written in C.

## Overview

Minishell is a functional shell that handles command execution, pipes, redirections, environment variable expansion, and signal management. Built as a team project.

### Features

- **Builtins:** `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **Pipes:** chain commands with `|`
- **Redirections:** `<`, `>`, `>>`, `<<` (heredoc)
- **Environment variables:** `$VAR` expansion, `$?` for exit status
- **Quotes:** single and double quote handling with proper expansion rules
- **Signals:** `Ctrl+C`, `Ctrl+D`, `Ctrl+\` behave like bash

### Key concepts

- **Lexer/Parser** architecture for tokenizing and parsing input
- **Process management** with `fork`, `execve`, `waitpid`
- **Pipe management** for inter-process communication
- **Signal handling** with `sigaction`

## Usage

```bash
make
./minishell
```
