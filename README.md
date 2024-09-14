# So_long

## Overview
**So_long** is a small 2D game where the player must collect all collectibles and escape through the exit. The game is built using the MiniLibX graphical library, with a focus on window management, textures, and event handling.

## Features
- 2D grid-based movement
- Basic sprite and texture handling
- Map validation and error handling
- Player movement via keyboard (W, A, S, D or arrow keys)

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/LAHMAMI1/So_long.git
    ```
2. Navigate to the project directory:
    ```bash
    cd So_long
    ```
3. Compile the game:
    ```bash
    make
    ```

## How to Play
1. Run the game with a `.ber` map file:
    ```bash
    ./so_long maps/map.ber
    ```
2. **Objective**: Collect all items (C), then find the exit (E).
3. **Movement**: Use `W`, `A`, `S`, and `D` or arrow keys to move up, left, down, and right respectively.
4. **Exit**: After collecting all collectibles, move to the exit to win the game.

## Game Rules
- The map consists of:
    - `0`: Empty space
    - `1`: Wall
    - `C`: Collectible
    - `E`: Exit
    - `P`: Player starting position
- The player cannot move through walls and must collect all collectibles before reaching the exit.
- The game displays the number of moves in the terminal.

## Map Requirements
- The map must be rectangular and surrounded by walls (`1`).
- It should contain at least one exit (`E`), one collectible (`C`), and one starting position (`P`).
- If the map is invalid, the game will display an error and exit.

## Example Map
```bash
1111111111111
10010000000C1
1000011111001
1P0011E000001
10001C0000011
1000110000C01
111C000001111
1111111111111
```

## Bonus Features
- Enemy patrols that cause the player to lose when touched.
- On-screen movement counter instead of terminal display.
- Simple sprite animations.
