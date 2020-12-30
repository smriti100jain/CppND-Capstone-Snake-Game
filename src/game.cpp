#include "game.h"
#include <iostream>
#include <thread>
Game::Game(std::size_t grid_width, std::size_t grid_height, int difficulty)
    : snake(grid_width, grid_height, difficulty),
      wall(grid_width, grid_height, difficulty){
        _foods.emplace_back(std::make_unique<FoodObj>(grid_width, grid_height, 4));
        _foods.emplace_back(std::make_unique<FoodObj>(grid_width, grid_height, 1));

}
void Game::reset_game(){
  game_state=GameState::running;
  score = 0;
}
Game::~Game(){};
void Game::set_game_state(GameState state){
  game_state = state;
}
GameState Game::Run(Controller  &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  //bool running = true;

  //initiate threads to simulate game objects (wall obstacle and food)
  wall.simulate();  
  for (auto it = std::begin(_foods); it != std::end(_foods); ++it){
    (*it)->simulate(snake.body);
  }
  

  while (game_state==GameState::running) {


    frame_start = SDL_GetTicks();
    // Input, Update, Render - the main game loop.
    controller.HandleInput(game_state, snake);
    Update();
    renderer.Render(snake, _foods[0]->get_game_object(), _foods[1]->get_game_object(), wall.get_game_object());
    frame_end = SDL_GetTicks();

    frame_count++;
    frame_duration = frame_end - frame_start;
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }
    
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }

    if(!snake.alive) game_state = GameState::dead;
  }
  return game_state;
}



void Game::Update() {
  
  // game over if snake touch the obstacle.................
  for (auto const &block : wall.get_game_object())        
    {
      for (auto const &item : snake.body)
      { 
        if(block.x == item.x && block.y == item.y) 
        {
          snake.alive = false;
        }
      }
      if (block.x == static_cast<int>(snake.head_x) && block.y == static_cast<int>(snake.head_y)) 
      {
        snake.alive = false;
      }
    }
    if (!snake.alive) return;
    snake.Update();
    int new_x = static_cast<int>(snake.head_x);
    int new_y = static_cast<int>(snake.head_y);

  	// Check if there's food over here
  	for (auto it = std::begin(_foods); it != std::end(_foods); ++it){
    
        int eaten = 0;
        for (auto const &food : (*it)->get_game_object()){
          if (food.x == new_x && food.y == new_y) {
            eaten +=1;
          }}
        if(eaten>0){
            (*it)->simulate(snake.body);
          	score = score + (*it)->get_score();
        }
        for(auto i=0; i<eaten;i++){
            // Grow snake and increase speed for every eaten food.
            snake.GrowBody();
            snake.speed += 0.02;
          }
      
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
