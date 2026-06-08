# Philosophers

**Grade: 100/100**

A simulation of the classic dining philosophers problem using threads and mutexes.

## Overview

A number of philosophers sit around a table with a fork between each pair. Each philosopher alternates between eating, sleeping, and thinking. A philosopher needs two forks to eat. The simulation stops if a philosopher dies of starvation (exceeds `time_to_die` without eating).

### Key concepts

- **POSIX threads** (`pthread_create`, `pthread_join`)
- **Mutexes** to prevent data races on shared resources (forks)
- **Concurrency** — avoiding deadlocks and race conditions
- Precise timing with `gettimeofday`

## Usage

```bash
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [meals_required]

# Example: 5 philosophers, 800ms to die, 200ms to eat, 200ms to sleep
./philo 5 800 200 200
```
