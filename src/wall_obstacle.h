#pragma once

#include "gameObject.h"
#include "SDL.h"


class wall_obstacle : public game_object
{
	public:
		enum class Direction { kUp, kDown, kLeft, kRight };
  		wall_obstacle(std::size_t grid_width, std::size_t grid_height, int challenge);
		void simulate() override;
    	void UpdateWall();
        void UpdateHead();
  		void UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell);
        virtual std::vector<SDL_Point> get_game_object() override;

	private:
  		float head_x;
  		float head_y;
  		int difficulty {0};
        float speed {0.1f};
        int grid_width;
    	int grid_height;
        int _wallLength;
 	 	std::mutex _mutex;
        Direction direction;

};