# so_long
so_long is the first graphical project from the 42 school, with the task of creating a simple game.

## Usage
so_long is developed for linux systems, and has the dependency of [minilibX](https://github.com/42Paris/minilibx-linux).
Compile with make, and run with "./so_long *path_to_map*". The map should be contained in a text file with a .ber extension. Possible characters include:
* 'C' - a collectible
* 'P' - the player's starting position
* 'E' - an exit
* '0' - a free space
* '1' - a wall
A valid map has to be surrounded by walls, and contain at least one collectible, one exit, and only one starting position for the player.

## Main concepts learned:
* Rendering an image to the screen
* Keyboard input
