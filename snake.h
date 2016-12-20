#ifndef _snake_h
#define _snake_h

#include "input.h"
#include <thread>
#include <semaphore.h>

class Snake
{
  public:
    Snake();
    void update_direction(enum Direction direction);
    enum Direction get_direction();

  private:
    pthread_t input_thread;
    sem_t snake_sema;
    enum Direction direction;
};

#endif