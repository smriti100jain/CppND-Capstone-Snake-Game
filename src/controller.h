#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "game_state.h"

#include <memory>

class Controller {
 public:

  void HandleInput(GameState &running, Snake &snake) ;
  

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif