# So Long

**Grade: 100/100**

A small 2D game built with the MiniLibX graphics library.

## Overview

The player navigates a top-down map, collects all items, and reaches the exit. The map is loaded from a `.ber` file and validated (rectangular, walled, with exactly one player, one exit, and at least one collectible). A flood-fill algorithm ensures the map is solvable.

### Key concepts

- **MiniLibX** for window management and sprite rendering
- **Event handling** (keyboard input, window close)
- **Map parsing** and validation with flood fill
- Move counter displayed in the terminal

## Usage

```bash
make
./so_long maps/map.ber
```
