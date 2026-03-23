# FdF - Fil de Fer

A 3D wireframe rendering program that visualizes height maps using isometric projection. This project implements a graphics visualization tool using the MLX library to create an interactive window displaying 3D terrain data.

## Overview

FdF (Fil de Fer, meaning "wireframe" in French) is a program that reads a 2D map file and renders it as a 3D isometric view. It displays height maps as wireframe models, allowing visualization of terrain and topographical data in three dimensions.

## Features

- **3D Wireframe Rendering**: Displays 2D height map data as 3D isometric projections
- **Color Support**: Supports colored vertices and height-based color gradients
- **Interactive Window**: Uses MLX library for graphical display
- **Line Drawing Algorithm**: Implements Bresenham's line drawing algorithm for smooth wireframe edges
- **Map Loading**: Parses map files containing height and optional color data
- **Utility Library**: Includes custom implementation of common C library functions (libft)

## Project Structure

```
.
├── libft/                 # Custom C library implementation
├── srcs/                  # Source files
│   ├── fdf.c             # Main program entry point
│   ├── fdf.h             # Main header file with data structures
│   ├── map.c             # Map rendering logic
│   ├── map_utils.c       # Map utility functions
│   ├── parsing.c         # Map file parsing
│   ├── read_map.c        # Map file reading
│   ├── draw_line.c       # Line drawing implementation
│   ├── colors_utils.c    # Color handling utilities
│   ├── utils.c           # General utility functions
│   ├── ft_atoi_base.c    # Base conversion utility
│   └── get_next_line/    # Line reading implementation
├── Makefile              # Build configuration
└── README.md            # This file
```

## Building

### Requirements
- `gcc` or compatible C compiler
- MLX library
- macOS (for default MLX framework setup)

### Compilation

```bash
make
```

This will:
1. Build the libft library
2. Compile all source files
3. Link with MLX frameworks
4. Generate the `fdf` executable

### Clean Build

```bash
make clean    # Remove object files
make fclean   # Remove executable and object files
```

## Usage

Run the program with a map file as an argument:

```bash
./fdf <map_file>
```

### Testing with Sample Maps

Test maps are provided in the `maps/test_maps/` directory. Try any of the following:

```bash
./fdf maps/test_maps/42.fdf
./fdf maps/test_maps/pyramide.fdf
./fdf maps/test_maps/mars.fdf
./fdf maps/test_maps/julia.fdf
```

Available test maps include:
- `42.fdf` - A simple 42 pattern
- `pyramide.fdf` - Pyramid shape
- `mars.fdf` - Mars terrain simulation
- `julia.fdf` - Julia set visualization
- And many more variations with different heights and color combinations

## Key Data Structures

### Map Structure (`s_map`)
- `matrix`: 2D array of height values
- `map_colors`: 2D array of color values
- `columns`: Width of the map
- `rows`: Height of the map
- `zoom`: Zoom/scale factor

### Image Structure (`s_img`)
- `img`: MLX image pointer
- `add`: Pixel buffer address
- `bpp`: Bits per pixel
- `s_line`: Size of one line in bytes
- `end`: Endianness flag

## Map File Format

Map files should contain height values arranged in rows and columns. Each value represents the height at that point:

```
0  0  0  0  0
0  10 10 10 0
0  10 20 10 0
0  10 10 10 0
0  0  0  0  0
```

Optional color values can be specified using hexadecimal notation after height values (e.g., `10,FF0000` for red).

## Implementation Details

- **Line Drawing**: Uses Bresenham's algorithm for efficient wireframe rendering
- **Coordinate System**: Converts 2D map coordinates to 3D isometric projection
- **Memory Management**: Implements custom memory allocation and string utilities via libft
- **File Parsing**: Reads and parses map files with support for variable dimensions and color data

## Technical Highlights

- Modular architecture with separate concerns for parsing, rendering, and utilities
- Custom string and memory functions eliminate external dependencies (except MLX and system libraries)
- Efficient pixel buffer management for real-time rendering
- Proper error handling and resource cleanup
