#pragma once
#include "gameObject.h"
#include "SDL.h"
#include <random>
#include <mutex>
#include <deque>
#include <condition_variable>


class FoodObj : public game_object
{
	public:
  		FoodObj(std::size_t grid_width, std::size_t grid_height, int score);
		void simulate() override;
        virtual std::vector<SDL_Point> get_game_object() override;
        void simulate(std::vector<SDL_Point> const  &snake_body);
        int get_score();
	private:
		int _numFood{1};
        int grid_width;
    	int grid_height;
        int _wallLength;
        int score;
 	 	std::mutex _mutex;
        std::random_device dev;
        std::mt19937 engine;
        std::uniform_int_distribution<int> random_w;
        std::uniform_int_distribution<int> random_h;
};