#pragma once
#include "SDL.h"
#include <vector>
#include <thread>
#include <mutex>



enum object_type
{
    no_object,
    food,
    obstacle_wall,
};

class game_object
{
	public:
      game_object();
      virtual ~game_object();
      int get_id() const { return id_; }
      object_type get_type() const { return type_; }
      virtual void simulate(){}
      virtual std::vector<SDL_Point> get_game_object(){};
	  std::vector<SDL_Point> game_object_vec;
      bool isOperating = true;

protected:
    object_type type_;                 //Identifies the class type
    int id_;                           //Every traffic object has its own unique id
    std::vector<std::thread> threads_; //Holds all threads that have been launched within this object

private:
    static int id_cnt_;                //Global variable for counting object ids
    

};