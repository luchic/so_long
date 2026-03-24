*This project has been created as part of the 42 curriculum by nluchini.*

# so_long

## Description
`so_long` is a small 2D game built in C with the MiniLibX-based `MLX42` graphics library. The goal of the project is to load a map from a `.ber` file, validate that it is playable, render it in a window, and let the player collect every collectible before reaching the exit.


## Features
- Loads maps from `.ber` files stored in `maps/`
- Validates map shape, characters, and reachable paths before starting the game
- Uses `MLX42` to create the window, draw tiles, and process keyboard input
- Tracks player movement and collectible progress
- Renders separate background, interactive, and animation layers
- Includes animated decorative/gameplay elements and end-game states

## Project Structure
```text
includes/
    internal.h
    ft_defs.h

src/
    core/
    parsing/
    validation/
    game/
    render/
    generate/
    tools/

maps/
textures/
libft/
```

## Instructions
### Requirements
You need a C compiler, `make`, `cmake`, and the system libraries required by `MLX42` and GLFW.

On Linux, that usually means having packages such as:
- `build-essential`
- `cmake`
- `git`
- `libglfw3-dev`
- OpenGL/X11 development libraries required by GLFW

### Compilation
Build the project from the repository root with:

```bash
make
```

The Makefile will:
- build `libft`
- clone `MLX42` automatically if the `mlx42/` directory is missing
- build `MLX42`
- compile the game executable as `./so_long`

### Execution
Run the program by passing a valid map file:

```bash
./so_long maps/small.ber
```

Other example maps are available in `maps/`, for example:

```bash
./so_long maps/middle1.ber
./so_long maps/big.ber
./so_long maps/enemies.ber
```

### Controls
- `W`, `A`, `S`, `D`: move the player
- `ESC` or window close button: quit the game

### Cleaning
```bash
make clean
make fclean
make re
```

## Map Format
A valid map must:
- use the `.ber` extension
- be rectangular
- be surrounded by walls
- contain exactly one player start
- contain at least one exit
- contain at least one collectible
- have a valid path so the player can reach collectibles and the exit

Typical map symbols used in `so_long` are:
- `1` for walls
- `0` for empty floor
- `P` for the player
- `C` for collectibles
- `E` for the exit
- additional symbols may be present in this version for extended gameplay/rendering

## Technical Notes
This project is organized into small modules for parsing, validation, gameplay, rendering, and generated layers. Types and function declarations are centralized in [includes/internal.h](/home/nluchini/core/projects/so_long/includes/internal.h), while shared structs and enums live in [includes/ft_defs.h](/home/nluchini/core/projects/so_long/includes/ft_defs.h).

The rendering side uses textures from `textures/` and composes multiple logical layers instead of drawing everything from a single raw map representation.

## Resources
Classic references related to the project:
- 42 project subject and intra materials for `so_long`
- MLX42 documentation: https://github.com/codam-coding-college/MLX42
- Flood fill overview: https://en.wikipedia.org/wiki/Flood_fill
- 42 `libft` project materials and standard C library references

### AI Usage
AI was used as a support tool during development and cleanup tasks, not as a substitute for understanding the code.

In this repository, AI assistance was used for tasks such as:
- reorganizing and merging header files
- improving file structure and README content
- reviewing naming, grouping, and code organization choices
- helping explain existing code and suggesting refactors

Core project logic, integration decisions, debugging, and final validation still required manual review and project-specific decisions by the author.

## Notes
This README documents the repository as it currently exists. If system dependencies for `MLX42` are missing on your machine, the build may fail until the required GLFW/OpenGL packages are installed.
