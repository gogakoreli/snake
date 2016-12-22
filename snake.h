#ifndef _snake_h
#define _snake_h

#include "input.h"
#include <thread>
#include <semaphore.h>
#include <vector>
#include <utility>
#include "macros.h"

using namespace std;

class Snake
{
public:
  Snake();
  void update_direction(enum Direction direction);
  void update_next_direction(enum Direction direction);
  enum Direction get_direction();
  void validate_direction();
  vector<pair<int, int>> snake_parts;
  pair<int, int> snake_head;
  void update_movement();
  void set_snake_food(pair<int, int> snake_food);
  bool food_eaten;
  bool is_dead;
  int length;

private:
  pthread_t input_thread;
  sem_t snake_sema;
  enum Direction direction;
  enum Direction next_direction;
  pair<int, int> snake_food;
  int snake_world_array[MAP_HEIGHT][MAP_WIDTH];
  void clear_snake_world();
  void initialize_snake();
};

#endif