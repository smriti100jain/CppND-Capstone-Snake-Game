# CPPND: Capstone Snake Game Example

This is a Snake Game repository for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

# GAME Features

+ GAME Controls
  + Press 'q' to quit the game
		+ Press 'SPACE' to pause the game
+ Game Features
		+ Moving Red Obstacle. If snake touches it, game is aborted.
		+ Multiple number of foods. Currently fixed to two kinds of food. (yellow food with score 4 and grey food with score 1)
		+ Growing snake
		+ There is a possibility to pause the game, then continue after some time or start a new game with a new player. You can also quit the game with 'q'.
+ User Input
		+ Before starting the game, the console asks for following information:
				+ challenge level (1 or 3 or 5)
						+ it is used to define the size of the red obstacle and speed of the moving obstacle and the food.
				+ player name
						+ player name is used to retreive last score for that player.
						+ in the end of the game, the player details with highest score is updated in the database.
						+ it is also used to promt the "congratulation" message if highest score is achieved.

# Implementation Details



## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
