# CPPND: Capstone Snake Game Example

This is a Snake Game repository for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

# GAME Features

+ **GAME Controls**

  + Press 'q' to quit the game

		+ Press 'SPACE' to pause the game
+ **Game Features**

		+ Moving Red Obstacle. If snake touches it, game is aborted.

		+ Multiple number of foods. Currently fixed to two kinds of food. (yellow food with score 4 and grey food with score 1)

		+ Growing snake

		+ There is a possibility to pause the game, then continue after some time or start a new game with a new player. You can also quit the game with 'q'.
+ **User Input**

		+ Before starting the game, the console asks for following information:

				+ challenge level (1 or 3 or 5)

						+ it is used to define the size of the red obstacle and speed of the moving obstacle and the food.

				+ player name

						+ player name is used to retreive last score for that player.

						+ in the end of the game, the player details with highest score is updated in the database.

						+ it is also used to promt the "congratulation" message if highest score is achieved.

# Class Structure

+ **resource_manager** [manager for all other classes. It start the game, pause, resets the game, ask for user input, displays game state and player related features ]

+ **players_database**  [ Read and writes players history (rank, best score, name). Prompts high score congratulations messages. ]

+ **controller**  [Interacts with user using keyboard. Lets user move the snake. Lets user pause or quit the game]

+ **render** [renders game(game objects, snake, scores) on the screen.]

+ **game** [stores game state. responsible for smoothly running the game.]

+ **snake** [ holds snake size, position ]

+ **gameObject** [super class for all game objects]

	+ **food** [runs simulation for food object. stores position of the food.]

	+ **wall_obstacle** [runs simulation for wall obstacle object. Stores it real time position.]


# Rubrics Metric
+ **Loops, Functions, I/O**

	* Code demonstrates the understanding of C++ functions and control structures. A lot of functions are added in resource_manager.cpp, wall_obstacle.cpp, players_database.cpp. A lot of control structures are also used like a while loop in UpdateWall function of wall_obstacle.cpp, almost all the functions of players_database.cpp.

	* Code accepts user input as added in resource_manager.cpp (like challenge level, player name). It also accepts 'q' key press and 'space' key press to quit or pause the game respectively.

	* Code reads data from a file and process data and writes data to the file as can be seend in add_player_best_score, is_high_score, write_players_data, load_players_data functions of the players_database.cpp.

+ **Object Oriented Programming**

	* game_manager.cpp class to manage the running of game, user input/output, data base handling is an example of oop behaviour.

	* there is a overloaded simulate(), simulate(std::vector<SDL_Point> const  &snake_body) in food.h.

	* The classes uses proper access specifier. Class objects communicates with memebes by setters and getters [eg: setting in line 133 resource_manager.cpp = game.set_game_state(GameState::running) for setting game state to running to continue the game. AND getter in line 96 (*it)->get_score() to get score from the food object.].

	* class constructors utilize member initialization list (eg: food.cpp[around line 9], wall_obstacle.cpp [line 7 to 10])

	* Classes follow an appropriate inheritance hierarchy [food.h and wall_obstacle.h  are inherited from gameObject]

	* derived class functions override virtual base class functions (as seen in virtual simulate() function in gameObject.cpp and wall_obstacle.cpp).

+ **Memory Management**

	* Project use smart pointers (line 30 game.h = std::unique_ptr<FoodObj>).

	* Project use references in function declaration (line 63 wall_obstacle.cpp).

+ **Concurrency**

	* Project uses multithreading (line 75 in wall_obstacle.cpp)

	* Project uses mutex (line 107, 94 in wall_obstacle.cpp)





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
