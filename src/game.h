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

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, int difficulty);
  ~Game();
  void Run(Controller  &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  int GetMoves() const;
  

 private:
  Snake snake;
  wall_obstacle wall;// = std::make_unique<Wall>();
  FoodObj food_;
  std::vector<std::unique_ptr<FoodObj>> _foods;
  bool running = true;
  int moves {0};
  int score{0};
  void Update();
};

#endif