#include "SDL.h"
#include <chrono>
#include "food.h"
#include <thread>
#include <iostream>
#include <queue>
#include <future>

FoodObj::FoodObj(std::size_t grid_width, std::size_t grid_height,  int score) :
 	 grid_width(grid_width),grid_height(grid_height),engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)),
  		 score(score) {
      
      	
      
}



bool in_snake(std::vector<SDL_Point> body, int x, int y){

  for(SDL_Point const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}


void FoodObj::simulate(std::vector<SDL_Point> const &body)
{		
  		int i, x,y;
    	game_object_vec.clear();
    	for(i=0;i<_numFood;i++){
          	while(true){
              x = random_w(engine);
              y = random_h(engine);
              // Check that the location is not occupied by a snake item before placing
              // food.
              if (!in_snake(body, x, y) && x < 32 && y < 32) {
                  SDL_Point food_;
                  food_.x = x;
                  food_.y = y;
				  game_object_vec.emplace_back(food_);					
                  break;
              }
            }
		}
}

void FoodObj::simulate()
{
  //futureThreadobj = exitThread.get_future();
  //update_thread = std::thread(&Wall::MoveWall, std::ref(futureThreadobj));
  //threads_.emplace_back(std::thread(&FoodObj::UpdateFood, this));
  return;
}


std::vector<SDL_Point> FoodObj::get_game_object()
{
  	return game_object_vec;
}
