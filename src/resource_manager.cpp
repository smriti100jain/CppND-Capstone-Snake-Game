#include "resource_manager.h"

resource_manager::resource_manager():database(){
}
resource_manager::~resource_manager(){
}
void resource_manager::initialize_new_game(){
  std::cout << "------------------------------------------------------------------- \n";
  std::cout << "----------------------   WELCOME TO SNAKE GAME  ------------------- \n";
  std::cout << "------------------------------------------------------------------- \n";

  display_game_controls();
  player_name = get_player_name();
  display_player_existing_profile();
  
}

void resource_manager::display_game_controls(){
  std::cout << "-------------GAME CONTROLS--------------\n";
  std::cout << "1. Press UP, DOWN, LEFT, RIGHT Arrow Keys to move the snake \n";
  std::cout << "2. Press SPACE BAR to pause the game \n";
  std::cout << "3. Press Q to quit the game \n";
  std::cout << "-------------GAME RUles--------------\n";
  std::cout << "1. Beware of Red Obstacle. \n";
  std::cout << "2. Yellow Food will give you score 4 \n";
  std::cout << "3. Grey Food will give score 1 \n";
  std::cout << "------------------------------------------------------------------- \n";
  std::cout << "------------------------------------------------------------------- \n";


}
std::string resource_manager::get_player_name(){
  std::string player_name;
  std::cout << "Please Enter Your Name: ";
  std::cin >> player_name;
  return player_name;
}
void resource_manager::display_player_existing_profile(){
  std::cout << "\n";
  std::cout << "------------------------------------------------------------------- \n";

  std::cout << "WELCOME TO The GAME: " << player_name << "\n";
  int rank = database.get_stored_player_rank(player_name);
  if (rank==0){
    std::cout << "This is your first game \n";
  }
  else{
    std::cout << "Your current rank is: " << rank << "\n";
  }
}

int resource_manager::get_challenge_level(){
  std::cout << "------------------------------------------------------------------- \n";

  std::cout << "Please choose the challenge level: \n";
  std::cout << "Easy (Press 1) \n";
  std::cout << "Medium (Press 3) \n";
  std::cout << "Hard (Press 5) \n";
  std::cout << "Please Enter the difficulty: ";
  std::cin >> challenge;

  while(!(challenge==1 || challenge==3 || challenge==5))
      {
      std::cout << "Invalid input, please try entering challenge again (challenge can be 1, 3 or 5): \n";
      std::cin >> challenge;
      }
  std::cout << "Challenge level chosen: " << challenge << "\n";
  return challenge;
}


int resource_manager::quit_game(){
  std::cout << "------------------------------------------------------------------- \n";

  std::cout << "To quit (press 1) \n";
  std::cout << "To continue this game(press 2) \n";
  std:: cout << "To start new game(press 3) \n";
  int quit;
  std::cin >> quit;
   while(!(quit==1 || quit==2 || quit==3))
      {
      std::cout << "Invalid input, please try entering (1 to quit and 2 to continue this game and 3 to start new game): \n";
      std::cin >> quit;
      }
  return quit;
}


void resource_manager::display_player_score(int score, int size){
  std::cout << "------------------------------------------------------------------- \n";

  std::cout << "Size: " << size << "\n";
  std::cout << "Current Score: " << score << "\n";
  int best_rank = database.get_stored_player_rank(player_name);
  if (best_rank !=0){
  std::cout << "Best Rank: " << best_rank << "\n";}
  if (database.is_high_score(score)){
  	std::cout << "......Congratulations: You have a new high score ......... \n";
      std::cout << "------------------------------------------------------------------- \n";

  }
  
}
void resource_manager::run_game(){
  initialize_new_game();
  // get player existing rank
  int challenge = get_challenge_level();
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Game game(kGridWidth, kGridHeight, 6 - challenge);
  Controller controller;
  
   while(true){
      GameState game_state = game.Run(controller, renderer, kMsPerFrame);
     if (game_state==GameState::quit or game_state==GameState::pause){
             std::cout << "------------------------------------------------------------------- \n";

       	display_player_score(game.GetScore(), game.GetSize());
      std::cout << "------------------------------------------------------------------- \n";

       if (game_state==GameState::quit){
         std::cout << "Are you sure you want to quit? \n";
       }
       else if(game_state==GameState::pause){
           std::cout << "------------------------GAME PAUSED -----------------------------\n";
       }

       int quit = quit_game();
        if(quit==1){
          database.add_player_best_score(player_name, game.GetScore());
          break;
        }
       else if (quit==2){
         game.set_game_state(GameState::running);
      	 continue;
       }
       else if (quit == 3){
         database.add_player_best_score(player_name, game.GetScore());
         game.reset_game();
         continue;
       }
      }
   	if (game_state==GameState::dead){
      std::cout << "---------------GAME OVER-------------------- \n";
      display_player_score(game.GetScore(), game.GetSize());
      database.add_player_best_score(player_name, game.GetScore());
      break;

      }
}
}


