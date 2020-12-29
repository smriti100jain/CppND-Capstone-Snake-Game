#include <algorithm>
#include "gameObject.h"



/* Init static variable */
int game_object::id_cnt_ = 0;

game_object::game_object()
{
	type_ = no_object;
	id_ = id_cnt_++;
}

game_object::~game_object()
{
    /* Set up thread barrier before this object is destroyed */
    isOperating = false;
    std::for_each(threads_.begin(), threads_.end(), [](std::thread &t) {
        t.join();
    });
}

