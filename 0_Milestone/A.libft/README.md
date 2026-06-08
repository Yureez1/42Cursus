# Libft

**Grade: 125/100**

A custom implementation of the C standard library. This is the first project at 42 and serves as the foundation for all future C projects.

## Overview

Libft recreates essential libc functions along with additional utility functions for string manipulation, memory management, linked lists, and file descriptor output.

### Functions implemented

**Libc functions:** `ft_atoi`, `ft_bzero`, `ft_calloc`, `ft_isalnum`, `ft_isalpha`, `ft_isascii`, `ft_isdigit`, `ft_isprint`, `ft_memchr`, `ft_memcmp`, `ft_memcpy`, `ft_memmove`, `ft_memset`, `ft_strchr`, `ft_strdup`, `ft_strlcat`, `ft_strlcpy`, `ft_strlen`, `ft_strncmp`, `ft_strnstr`, `ft_strrchr`, `ft_tolower`, `ft_toupper`

**Additional functions:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

**Bonus (linked lists):** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Usage

```bash
make        # Compile the library
make bonus  # Compile with bonus functions
make clean  # Remove object files
make fclean # Remove object files and library
```
