#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>

using std::string;
using std::vector;

class players_database
{

public:
    players_database(); // loads data from the file
    ~players_database(); // write updated data to file
    int get_stored_player_rank(std::string player_name); // return 0 if new player
    bool is_high_score(int score);
    void add_player_best_score(std::string player_name, int score);
private:
	typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
	  const std::string database_file_path{"../data/game_database.txt"};
      std::map<string, int> players_name_to_best_score_map;
      void load_players_data();
      void write_players_data();
      void sort_players_score_map();
};