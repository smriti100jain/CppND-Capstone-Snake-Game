#include "SDL.h"
#include <chrono>
#include "wall_obstacle.h"
#include <thread>
#include <iostream>

wall_obstacle::wall_obstacle(std::size_t grid_width, std::size_t grid_height, int challenge) :
 	head_x(0),
  	head_y(0), grid_width(grid_width),grid_height(grid_height),_wallLength(grid_width/challenge),
  	difficulty(challenge), direction(Direction::kRight) {

  for (int i = 0; i < _wallLength; i ++)  
    {
      SDL_Point block{
      static_cast<int>(head_x) + i,
      static_cast<int>(head_y)};
      game_object_vec.push_back(block);
    }
}




void wall_obstacle::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      if (head_y - speed > 0){
      	head_y -= speed;}
      else{
      	direction = Direction::kRight;
      	head_x += speed;
      }
      break;

    case Direction::kDown:
      if (head_y + speed < grid_height){
      	head_y += speed;}
      else{
      	direction = Direction::kLeft;
      	head_x -= speed;
      }
      break;

    case Direction::kLeft:
      if (head_x - speed > 0){
      	head_x -= speed;}
      else{
      	direction = Direction::kUp;
      	head_y -= speed;
      }
      break;

    case Direction::kRight:
      if (head_x + speed < grid_width){
      	head_x += speed;}
      else{
      	direction = Direction::kDown;
      	head_y += speed;}
      break;
  }
}

void wall_obstacle::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
   // Add previous head location to vector
   game_object_vec.push_back(prev_head_cell);
   // Remove the tail from the vector.
   game_object_vec.erase(game_object_vec.begin());
}


void wall_obstacle::simulate()
{
  //futureThreadobj = exitThread.get_future();
  //update_thread = std::thread(&Wall::MoveWall, std::ref(futureThreadobj));
  threads_.emplace_back(std::thread(&wall_obstacle::UpdateWall, this));
}

void wall_obstacle::UpdateWall()
{
  while(isOperating ==true) {
    {    
         SDL_Point prev_cell{
          static_cast<int>(head_x),
          static_cast<int>(
              head_y)};  // We first capture the head's cell before updating.
        UpdateHead();
        SDL_Point current_cell{
            static_cast<int>(head_x),
            static_cast<int>(head_y)};  // Capture the head's cell after updating.
		
        // Update all of the body vector items if the snake head has moved to a new
        // cell.
        if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
          std::lock_guard<std::mutex> lck(_mutex);
          UpdateBody(current_cell, prev_cell);
        }
    }
  
    std::this_thread::sleep_for(std::chrono::milliseconds(difficulty));    //Delay to control speed of wall moving, also helps with thread data access

  }
}


std::vector<SDL_Point> wall_obstacle::get_game_object()
{
  std::lock_guard<std::mutex> lck(_mutex);
  return game_object_vec;
}
