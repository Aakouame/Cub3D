Cub3D is a project that implements a raycasting algorithm to create a 3D representation of a 2D grid or map. The project is written in C and uses the minilibx library for rendering the resulting image on the screen.

// gif playing cub3d

The project includes a Makefile that can be used to build and install the project and its dependencies. To build and run the project, you will need to have the minilibx library installed on your system. Once you have installed minilibx, you can use the provided Makefile to build and run the project.

The project takes a .cub file as input, which contains a grid of characters representing the 2D map or scene that the raycasting algorithm will be used to render. The .cub file should use the following conventions:

    '1' represents a wall or solid object in the scene
    '0' represents a free space or open area in the scene
    'W', 'S', 'E', or 'N' represents the direction of the player's field of view

[Example .cub file](./younes.cub)

```
C 225,255,0
SO ./s.txt
EA ./e.txt
WE ./w.txt  
NO ./n.txt                     
F 225,255,0

11111111111111111
10000000000000001
10000000000000001
10000000000000001
10000000000000001
10000000000000001
10000000E000000001
10000000000000001
10000000000000001
10000000000000001
10000000000000001
10000000000000001
10000000000000001
11111111111111111
```

Once you have provided a .cub file as input, you can run the project to render the 3D representation of the map on the screen. The project also supports user input, allowing you to move the viewpoint around the scene and interact with the environment using the arrow keys to rotate the player's field of view and the W/S/A/D keys to move forward, backward, left, and right, respectively.

Screenshot of Cub3D with user input

Overall, Cub3D is a well-implemented project that provides a working example of a raycasting algorithm in C using the minilibx library. The project is well-documented and easy to build and run, making it a useful resource for anyone interested in learning more about raycasting or implementing a similar algorithm.

## Collaboration with @Y-askour
