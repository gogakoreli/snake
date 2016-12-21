#ifndef _snake_map_h
#define _snake_map_h

#include "snake.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define MAP_CHAR '.'
#define MAP_END 30
#define SNAKE_CHAR 'O'
#define SNAKE_HEAD_WEST '<'
#define SNAKE_HEAD_NORTH '^'
#define SNAKE_HEAD_EAST '>'
#define SNAKE_HEAD_SOUTH 'V'
#define SNAKE_FOOD_CHAR '*'

class SnakeMap
{
public:
  SnakeMap(Snake *snake);
  void redraw();
  pair<int, int> snake_food;
  void update_snake_food();

private:
  char map_array[MAP_HEIGHT][MAP_WIDTH];
  Snake *snake;
};

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH]);
void update_snake_head(char map_array[MAP_HEIGHT][MAP_WIDTH], Snake *snake);

#endif