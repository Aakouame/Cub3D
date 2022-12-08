Cub3D is a project that implements a raycasting algorithm to create a 3D representation of a 2D grid or map. The project is written in C and uses the minilibx library for rendering the resulting image on the screen.

The project includes a Makefile that can be used to build and install the project and its dependencies. To build and run the project, you will need to have the minilibx library installed on your system. Once you have installed minilibx, you can use the provided Makefile to build and run the project.

The project takes a .cub file as input, which contains a grid of characters representing the 2D map or scene that the raycasting algorithm will be used to render. The .cub file should use the following conventions:

    '1' represents a wall or solid object in the scene
    '0' represents a free space or open area in the scene
    'W', 'S', 'E', or 'N' represents the direction of the player's field of view

The project includes a sample .cub file that you can use as a starting point. Once you have provided a .cub file as input, you can run the project to render the 3D representation of the map on the screen. The project also supports user input, allowing you to move the viewpoint around the scene and interact with the environment.

Overall, Cub3D is a well-implemented project that provides a working example of a raycasting algorithm in C using the minilibx library. The project is well-documented and easy to
