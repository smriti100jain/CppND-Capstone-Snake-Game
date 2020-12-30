#pragma once
#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <thread>
#include <chrono>
#include <limits>
#include "game_state.h"
#include "players_database.h"

class resource_manager
{
	public:
    	resource_manager();
        ~resource_manager();
        void run_game();
        
	private:
    	int pause_game();
        int quit_game();
        void game_over();
		void initialize_new_game();
        void display_game_controls();
        std::string get_player_name();
        void display_player_existing_profile();
        int get_challenge_level();
        void display_player_score(int, int);

        std::string player_name;
        players_database database;
        int challenge;
        std::size_t kFramesPerSecond{60};
        std::size_t kMsPerFrame{1000 / kFramesPerSecond};
        std::size_t kScreenWidth{640};
        std::size_t kScreenHeight{640}; //640
        std::size_t kGridWidth{32};
        std::size_t kGridHeight{32};
        
};