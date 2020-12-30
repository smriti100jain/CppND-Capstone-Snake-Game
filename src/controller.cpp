#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(GameState &game_state, Snake &snake)  {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_KEYDOWN) {

      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
        case SDLK_q:
          game_state = GameState::quit;
          break;
        case SDLK_SPACE:
          game_state = GameState::pause;
          break;
                    
      }
    }
  }
}