#include "players_database.h"

players_database::players_database(){
  load_players_data();
};
players_database::~players_database(){};

void players_database::load_players_data(){
  std::cout << "---------------Loading exisiting players database........\n";
  std::ifstream filestream(database_file_path);
  if (filestream.is_open()){ 
    std::string line;
    while (std::getline(filestream, line)){
	  std::string name;
  	  int score; int rank;
      std::istringstream linestream(line);
      while (linestream >> rank >> name >> score)
      {
        players_name_to_best_score_map.insert(std::make_pair(name, score));
      }}
    std::cout << "Loaded total players: " << players_name_to_best_score_map.size() << "\n";
    std::cout << "\n";
    filestream.close();}
  else
  { //create an empty game database file.
    std::cout << "creating an empty file......................\n";
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
    	it++;
  }
  database_file.close();
}
bool players_database::is_high_score(int score){
  int current_best_score = 0;
    std::map<std::string, int>::iterator it = players_name_to_best_score_map.begin();

  while(it != players_name_to_best_score_map.end())
  {	
      current_best_score = it->second;
      break;
     it++;
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
    write_players_data();
  }
  else{
    if(players_name_to_best_score_map[player_name]<score){
      players_name_to_best_score_map[player_name] = score;
      sort_players_score_map();
      write_players_data();
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
    	it++;
  }
  return rank;
  
}
bool compare(std::pair<std::string, int> player1, std::pair<std::string, int> player2) 
{ 
    return player1.second > player2.second;
} 
void players_database::sort_players_score_map(){
	typedef std::pair<std::string,int> pair;

  // create an empty vector of pairs
    std::vector<pair> vec;
    // copy key-value pairs from the map to the vector
    std::copy(players_name_to_best_score_map.begin(),
            players_name_to_best_score_map.end(),
            std::back_inserter<std::vector<pair>>(vec));
 
    // sort the vector by decreasing order of its pair's second value
    // if second value are equal, order by the pair's first value
    std::sort(vec.begin(), vec.end(),
            [](const pair& l, const pair& r) {
                if (l.second != r.second)
                    return l.second > r.second;
 
                return l.first < r.first;
            });
  	int count = 0;
  	int max_players = 10;
 	players_name_to_best_score_map.clear();
    for (std::pair<std::string, int> element : vec)
  	{
      if (count>max_players){
      	break;
      }
      players_name_to_best_score_map.insert(std::make_pair(element.first,  element.second));
      count = count + 1;
      
     }

}



  
