# Cub3D 

[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/powered-by-coffee.svg)](https://forthebadge.com)

This project is inspired by the classic game Wolfestein. 
As of right now the core elements of the project are implemented.

## Installation

For macOS:

```bash
cd cub3d && make && ./cub3D map.cub
```
For Linux:

```bash
cd cub3d && cd cub3D-linux && make && ./cub3D map.cub
```
## Usage


```
## Keybinds

Player Movement: 
- W: Move Forward
- S: Move Backwards
- D: Strafe right
- A: Strafe right
- Right Arrow: Rotate right
- Left Arrow: Rotate left
- ESC key: exit program

## Program

The program accepts two arguments, the first one is for the file with .cub extension that hosts the following:
- Screen Resolution
- Paths for textures and sprites
- RGB data for ceiling and floor
- The map itself represented by:
   - 0 for empty space
   - 1 for Walls
   - 2 for Sprites
The second argument, if "--save", will save the first rendered frame as a BMP file at the root of the project.
