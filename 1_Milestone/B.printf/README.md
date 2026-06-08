# ft_printf

**Grade: 100/100**

A custom implementation of the `printf` function from the C standard library.

## Overview

`ft_printf` handles the following format specifiers: `%c` (character), `%s` (string), `%p` (pointer), `%d` / `%i` (signed integer), `%u` (unsigned integer), `%x` / `%X` (hexadecimal), and `%%` (literal percent sign).

### Key concepts

- **Variadic functions** using `<stdarg.h>`
- Format string parsing
- Base conversion (decimal, hexadecimal)

## Usage

```bash
make
```

Then include `ft_printf.h` and link the library in your project.
