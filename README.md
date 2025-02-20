# Terminal Snake Escape Game

A console-based snake escape game, built in C89 standard.

## Table of Contents
- [Terminal Snake Escape Game](#terminal-snake-escape-game)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [Requirements](#requirements)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Gameplay](#gameplay)
    - [Controls](#controls)
    - [Game Flow](#game-flow)
  - [Project Structure](#project-structure)
    - [Key Dependencies](#key-dependencies)
  - [Development](#development)
    - [Build Standards](#build-standards)
    - [Memory Management](#memory-management)
    - [Map File Format](#map-file-format)

## Features
- Procedural grid maze generation
- Save/load game state functionality after every move
- undo game state functionality
- Interactive rule system
- Input validation with error handling
- Memory leak detection (via Valgrind)

## Requirements
- Linux environment
- GCC compiler (version 9.4.0 or newer)
- GNU Make (version 4.2.1 or newer)
- Valgrind (for memory leak checking)

## Installation

```bash
# Install build essentials
sudo apt update && sudo apt install build-essential make valgrind

# Clone repository
git clone https://github.com/haikalllp/Unix-Assignment2-SnakeEscape-Linux
cd SnakeEscapeGame
```

## Usage

```bash
# Compile project
make

# Run with default map
./eat map.txt

# Clean build artifacts
make clean
```

## Gameplay

### Controls
| Key | Action          |
|-----|-----------------|
| w   | Move up         |
| a   | Move left       |
| s   | Move down       |
| d   | Move right      |
| u   | undo move       |
| q   | Quit game       |

### Game Flow
1. Rules screen displayed at startup
2. Press Enter to begin
3. Navigate player (p) around the map.
4. Collect food (@) while avoid being eaten by snake (~).
5. Player can undo their move using 'U'.

## Project Structure

```text
.
├── main.c        - Entry point and game loop
├── game.[ch]     - Core game logic and state management
├── input.[ch]    - Input handling and validation
├── randomGen.[ch]- Procedural maze generation
├── rules.[ch]    - Rule system and UI displays
├── sleep.[ch]    - Timing controls for animations
├── gameSavesLL.[ch] - Save file linked list implementation
└── makefile      - Build system with Valgrind support
```

### Key Dependencies
| Module        | Dependencies                          |
|---------------|---------------------------------------|
| game.o        | randomGen.h, sleep.h, input.h         |
| input.o       | game.h, gameSavesLL.h                 |
| main.o        | game.h, rules.h, gameSavesLL.h        |

## Development

### Build Standards
```bash
# Compile with strict C89 compliance
CFLAGS = -Wall -ansi -pedantic -Werror -g
```

### Memory Management
```bash
# Run with Valgrind memory checker
make valgrind
```

### Map File Format
Create custom maps using this structure:
```text
7 9
0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 3 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 2 0 0
0 0 0 0 0 0 0 0 0
```

- First line: [rows] [columns] [7,9]
- Numerical key:
  - 0: Grid space
  - 1: Start position of player (p)
  - 2: Snake position (~)
  - 3: Food position (@)
- Ensure file is saved as .txt

*Project created for UNIX Programming Assignment - © 2024*