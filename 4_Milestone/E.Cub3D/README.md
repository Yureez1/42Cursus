# Cub3D

**Grade: 110/100**

A 3D raycasting engine inspired by Wolfenstein 3D, built with MiniLibX.

## Overview

Cub3D renders a first-person view of a maze from a 2D map using the raycasting technique. The player can move through the environment and look around in real time.

### Features

- **Raycasting** engine with textured walls (N/S/E/W)
- **Map parsing** from `.cub` files with validation
- **Player movement** (WASD) and rotation
- Configurable floor and ceiling colors

### Bonus features

- **Minimap** overlay
- **Wall collision** detection
- **Mouse rotation**

### Key concepts

- **Raycasting** algorithm (DDA)
- **Texture mapping** on wall surfaces
- **2D/3D math** — trigonometry, vector operations
- **MiniLibX** for rendering and event handling

## Usage

```bash
make         # Mandatory part
make bonus   # With bonus features
./cub3D maps/good/cheese_maze.cub
```
