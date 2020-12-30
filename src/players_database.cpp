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
#include "players_database.h"

using std::string;
using std::vector;

//-------------------------------------------------------------------------------------------//

players_database::players_database(){
  load_players_data();
};
players_database::~players_database(){write_players_data();};

void players_database::load_players_data(){
  std::ifstream filestream(database_file_path);
  if (filestream.is_open()){ 
    std::string line;
    while (std::getline(filestream, line)){
	  std::string name;
  	  int score;
      std::istringstream linestream(line);
      while (linestream >> name >> score)
      {
        players_name_to_best_score_map.insert(std::make_pair(name, score));
      }}
    filestream.close();}
  else
  { //create an empty game database file.
    std::ofstream database_file(database_file_path);
    database_file.close();
  }
}

void players_database::write_players_data(){
  std::ofstream database_file(database_file_path, std::ofstream::trunc); // To "erase" the contents of a file before writing new content
  if (!database_file.is_open()){std::cout << "CANNOT OPEN DATABASE FILE...EXITING....." << std::endl;}
  std::map<std::string, int>::iterator it = players_name_to_best_score_map.begin();
  int rank = 1;
  while(it != players_name_to_best_score_map.end())
  {
      // rank name bestscore
       database_file << rank << " " << it->first << " " << it->second << "\n";
       rank = rank + 1;
  }
}
bool players_database::is_high_score(int score){
  int current_best_score = 0;
    std::map<std::string, int>::iterator it = players_name_to_best_score_map.begin();

  while(it != players_name_to_best_score_map.end())
  {	
      current_best_score = it->second;
      break;
  }
  if (score>current_best_score){
    return true;
  }
    else{
      return false;
    }  
}

void players_database::add_player_best_score(std::string player_name, int score){
  int player_rank = get_stored_player_rank(player_name);
  if (player_rank==0){
    players_name_to_best_score_map.insert(std::make_pair(player_name, score));
    sort_players_score_map();
  }
  else{
    if(players_name_to_best_score_map[player_name]<score){
      players_name_to_best_score_map[player_name] = score;
      sort_players_score_map();
    }
  }
}
int players_database::get_stored_player_rank(std::string player_name){
  //returns the rank of the player from his past games. If new player returns 0
  std::map<std::string, int>::iterator it = players_name_to_best_score_map.begin();
  int rank = 0; int count = 0;
  while(it != players_name_to_best_score_map.end())
  {
      // rank name bestscore
      if (it->first==player_name){
        rank = count+1;
        break;
      }
       count = count + 1;
  }
  return rank;
  
}

void players_database::sort_players_score_map(){
  Comparator comparison_function =
      [](std::pair<std::string, int> player1, std::pair<std::string, int> player2) {
        return player1.second > player2.second; // decreasing order of score.
      };
 // sort in decreasing order of score
  std::set<std::pair<std::string, int>, Comparator> players_name_to_best_score_map(
      players_name_to_best_score_map.begin(), players_name_to_best_score_map.end(), comparison_function);

}



  
