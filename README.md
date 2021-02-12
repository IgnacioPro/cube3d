# Cub3D 

This project is inspired by the classic game Wolfestein. 
## Installation

For macOS:

```bash
cd cub3d && make && ./cub3D map.cub
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

The program accepts two arguments, the first one is for the file with 
.cub extension thats hosts the following:
- Screen Resolution
- Paths for textures and sprites
- RGB data for ceiling and floor
- The map itself represented by:
   - 0 for empty space
   - 1 for Walls
   - 2 for Sprites
