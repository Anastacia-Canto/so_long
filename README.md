# so_long

<img src="https://img.shields.io/badge/graphics-MinilibX-0000FF"> <img src="https://img.shields.io/badge/OS-Linux-0000FF"> <img src="https://img.shields.io/badge/game-2D-0000FF">

The objective of this project is to create a simple 2D game. The theme choosen was Sonic, like the SEGA game.
So, Sonic has to escape after collecting all the rings, but game is over if he touchs Robotinik!

![](https://github.com/Anastacia-Canto/so_long/blob/main/Peek%202022-09-15%2015-53.gif)

## Skills

 - Window management
 - Event handling
 - Image manipulation
 - Usage of graphical library (MinilibX)
 
 
## Development rules

 - Program only accepts map files with ".ber" extension, by command line argument
 - The map should have only the following characters:
    - 'P' for player (only one)
    - 'C' for ring (at leaste one)
    - 'E' for exit (only one)
    - '1' for wall
    - '0' for free way
  - The map must be surrounded for walls
  - The map must be rectangular
 
 If one of these requirements are not ok, the program returns an error and cleans all the heap memory.
 
## Usage

The program runs only on Linux. Use the following commands to play:

```
git clone https://github.com/Anastacia-Canto/so_long.git

make

./so_long ../maps/map3.ber

```
You can change the map, changing the path. Another option is "../maps/map2.ber". 
You can even make your own maps! But remember to respect the map rules!

Use the keys 'W', 'A', 'S' and 'D' to move the player and 'ESC' or 'x' button to quit.
The exit only opens when all the rings are collected. If Sonic touchs Robotinik the game is over.
