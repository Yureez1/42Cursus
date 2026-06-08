# Push_swap

**Grade: 96/100**

Sort a stack of integers using a limited set of operations in the fewest moves possible.

## Overview

Given a stack of random integers, the program outputs a sequence of instructions to sort it using only two stacks (`a` and `b`) and the following operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

### Key concepts

- **Sorting algorithms** optimized for a constrained instruction set
- **Algorithm complexity** — minimizing the number of operations
- **Linked lists** for stack implementation
- Index-based sorting strategy

## Usage

```bash
make
./push_swap 3 1 5 2 4
# Outputs the list of operations to sort the stack

# Verify with checker:
ARG="3 1 5 2 4"; ./push_swap $ARG | wc -l
```
