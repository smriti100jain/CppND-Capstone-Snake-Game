#ifndef GAME_H
#define GAME_H
#include "food.h"
#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include<mutex>
#include<thread>
#include <iostream>
#include "wall_obstacle.h"
#include <future>
#include "game_state.h"
class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, int difficulty);
  ~Game();
  GameState Run(Controller  &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  void reset_game();
  int GetScore() const;
  int GetSize() const;
  void set_game_state(GameState state);
  

 private:
  Snake snake;
  wall_obstacle wall;// = std::make_unique<Wall>();
  std::vector<std::unique_ptr<FoodObj>> _foods;
  GameState game_state{GameState::running};
  int score{0};
  void Update();
};

#endif