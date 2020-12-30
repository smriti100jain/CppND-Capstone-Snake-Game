#include "resource_manager.h"
int main(){
  resource_manager manager;
  manager.run_game();
  return 0;
}


// #include <iostream>
// #include "controller.h"
// #include "game.h"
// #include "renderer.h"
// #include <thread>
// #include <chrono>
// #include <limits>
// #include "game_state.h"
// void __init__game(){
// }
// int main() {
//   constexpr std::size_t kFramesPerSecond{60};
//   constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
//   constexpr std::size_t kScreenWidth{640};
//   constexpr std::size_t kScreenHeight{640}; //640
//   constexpr std::size_t kGridWidth{32};
//   constexpr std::size_t kGridHeight{32};
//   int challenge;
//   std::cout << "----------------------   WELCOME TO SNAKE GAME  ------------------- \n";
//   std::cout << "Please choose the challenge level: \n";
//   std::cout << "Easy (Press 1) \n";
//   std::cout << "Medium (Press 3) \n";
//   std::cout << "Hard (Press 5) \n";
//   std::cout << "Please Enter the difficulty: ";
//   std::cin >> challenge;

//   while(!(challenge==1 || challenge==3 || challenge==5))
//       {
//       std::cout << "Invalid input, please try entering challenge again (challenge can be 1, 3 or 5): \n";
//       std::cin >> challenge;
//       }
//   std::cout << "Challenge level chosen: " << challenge << "\n";

  
//   Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
//   Controller controller;
//   Game game(kGridWidth, kGridHeight, 6 - challenge);
//   while(true){
//       GameState game_state = game.Run(controller, renderer, kMsPerFrame);
//       if (game_state==GameState::quit){
//         std::cout << "Are you sure you want to quit? \n";
//         std::cout << "To quit (press 1) \n";
//         std::cout << "To continue (press 0) \n";
//         int quit;
//         std::cin >> quit;
//         if(quit==1){
//           std::cout << "Quitting the game \n";
//           break;
//         }
//         continue;
//       }
//     if (game_state==GameState::dead){
//       std::cout << "---------------GAME OVER-------------------- \n";
//       std::cout << "Size: " << game.GetSize() << "\n";
//       std::cout << "Score: " << game.GetScore() << "\n";
//       break;

//       }
//     if (game_state==GameState::pause){
//       std::cout << "---------------YOU PAUSED THE GAME-------------------- \n";
//       std::cout << "Current Size: " << game.GetSize() << "\n";
//       std::cout << "Current Score: " << game.GetScore() << "\n";
//       std::cout << "To continue (press 1) \n";
//       std::cout << "To quit (press 0) \n";
//         int continue_;
//         std::cin >> continue_;
//         if(continue_==0){
//           std::cout << "Quitting the game \n";
//           break;
//         }
//       game.set_game_state(GameState::running);
//       continue;
//     }
      
  
  
// }
//   return 0;
// }