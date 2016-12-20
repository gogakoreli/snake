#ifndef _snake_map_h
#define _snake_map_h

#include "snake.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define MAP_CHAR '.'
#define MAP_END 30
#define SNAKE_CHAR 'O'

class SnakeMap
{
public:
  SnakeMap(Snake *snake);
  void redraw();

private:
  char map_array[MAP_HEIGHT][MAP_WIDTH];
  Snake *snake;
};

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH]);

#endif