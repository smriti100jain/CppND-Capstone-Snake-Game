#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}
void Renderer::Render(Snake const snake, std::vector<SDL_Point> const food1,std::vector<SDL_Point> const food2, std::vector<SDL_Point> const wall) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;


  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
  SDL_RenderClear(sdl_renderer);

  //Render Wall
  SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 255);
  for (int i = 0; i < wall.size(); i++) {
    block.x = wall[i].x * block.w;
    block.y = wall[i].y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
}

  // Render food1
  SDL_SetRenderDrawColor(sdl_renderer, 255, 223,0,255);
   for (int i = 0; i < food1.size(); i++) {
    block.x = food1[i].x * block.w;
    block.y = food1[i].y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
}
  // Render food2
  SDL_SetRenderDrawColor(sdl_renderer, 128, 128, 128, 255);
   for (int i = 0; i < food2.size(); i++) {
    block.x = food2[i].x * block.w;
    block.y = food2[i].y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
}
 
  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}


void Renderer::UpdateWindowTitle(int score, int fps, int moves) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps) + " Move Counter: " + std::to_string(moves)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}