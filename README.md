# <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Activities/Video%20Game.png" alt="Video Game" width="25" height="25" /> cub3D

<div align=center>
  
  ![badge](https://raw.githubusercontent.com/angelamcosta/angelamcosta/main/42_badges/cub3dn.png)

  <table>
  <tr>
    <td align="center"><a href="http://github.com/mgdiogo"><img src="https://avatars.githubusercontent.com/u/109535612?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Miguel Diogo</b></sub></a><br /><a href="https://github.com/mgdiogo/" title="Miguel Diogo"></a></td>
    <td align="center"><a href="https://github.com/angelamcosta"><img src="https://avatars.githubusercontent.com/u/14792447?v=4?s=100" width="100px;" alt=""/><br /><sub><b>Angela Lima</b></sub></a><br /><a href="https://github.com/angelamcosta" title="Angela Lima"></a></td>
  </tr>
</table>
  
</div>

## Project Description:

cub3D is a project that involves creating a "realistic" 3D graphical representation of the interior of a maze from a first-person perspective. This representation is achieved using Ray-Casting principles. The subject of the project can be found [here](https://raw.githubusercontent.com/angelamcosta/cub3d/main/en.subject.pdf).

## Mandatory Features:

-   The program should be capable of setting the floor and ceiling colors with two different colors.
-   It displays the image in a window and follows these rules:
    -   Left and right arrow keys allow the user to look left and right in the maze.
    -   W, A, S, and D keys allow movement through the maze.
    -   Pressing ESC should close the window and exit the program cleanly.
    -   Clicking the red cross in the window frame should close the window and exit the program cleanly.
    -   The use of miniLibX images is recommended.

## Additional Features (BONUS):

-   Wall collisions.
-   A minimap system.
-   Doors that can be opened and closed.
-   Animated sprites.
-   Rotating the viewpoint with the mouse.

## Makefile Requirements:

-   Available commands in the Makefile are: all, clean, fclean, re, bonus.

## Map Analysis:

-   The program takes a scene description file with the .cub extension as its first argument.
-   The map should consist only of 6 possible characters: 0 for an empty space, 1 for a wall, and N, S, E, or W for the player's starting position and orientation.
-   The map should be enclosed/surrounded by walls; otherwise, the program should return an error.
-   Each element (except the map) has a type identifier (composed of one or two characters), followed by specific information for each object in a strict order.

## Project Submission Instructions:

-   All files must be included in the submission.
-   The Makefile must contain the commands: all, clean, fclean, re, bonus.
-   External functions such as open, close, read, write, printf, malloc, free, perror, strerror, exit, all math library functions (-lm), and all miniLibX library functions are allowed.
-   The use of the Libft library is permitted.
-   The project must be submitted in \*.cub format.
