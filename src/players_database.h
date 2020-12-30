#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>


class players_database
{

public:
    players_database(); // loads data from the file
    ~players_database(); // write updated data to file
    int get_stored_player_rank(std::string player_name); // return 0 if new player
    bool is_high_score(int score);
    void add_player_best_score(std::string player_name, int score);

private:
	  const std::string database_file_path{"../src/game_database.txt"};
      std::map<std::string, int> players_name_to_best_score_map;
      void load_players_data();
      void sort_players_score_map();
      void write_players_data();

};