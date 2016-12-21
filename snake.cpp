#include "snake.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>
#include "snake_map.h"

using namespace std;

void *input_thread_work(void *arg)
{
    struct Snake *snake = (struct Snake *)arg;
    while (true)
    {
        enum Direction direction = get_input();
        snake->update_next_direction(direction);
    }
}

Snake::Snake(void)
{
    direction = East;
    food_eaten = false;
    snake_parts.push_back(make_pair(MAP_HEIGHT / 2, MAP_WIDTH / 2 - 1));
    snake_parts.push_back(make_pair(MAP_HEIGHT / 2, MAP_WIDTH / 2));
    snake_head = make_pair(MAP_HEIGHT / 2, MAP_WIDTH / 2 + 1);
    snake_parts.push_back(snake_head);
    sem_init(&snake_sema, 0, 1);
    pthread_create(&input_thread, NULL, input_thread_work, this);
}

void Snake::update_direction(enum Direction direction)
{
    sem_wait(&this->snake_sema);
    switch (direction)
    {
    case West:
        if (this->direction != East)
        {
            this->direction = direction;
        }
        break;
    case North:
        if (this->direction != South)
        {
            this->direction = direction;
        }
        break;
    case East:
        if (this->direction != West)
        {
            this->direction = direction;
        }
        break;
    case South:
        if (this->direction != North)
        {
            this->direction = direction;
        }
        break;
    }
    sem_post(&this->snake_sema);
}

void Snake::update_next_direction(enum Direction direction)
{
    this->next_direction = direction;
}

enum Direction Snake::get_direction(void)
{
    enum Direction result = East;
    sem_wait(&this->snake_sema);
    result = this->direction;
    sem_post(&this->snake_sema);
    return result;
}

void Snake::validate_direction(void)
{
    if (next_direction != Error)
    {
        update_direction(next_direction);
    }
}

void Snake::update_movement(void)
{
    pair<int, int> movement_part;
    enum Direction direction = get_direction();
    switch (direction)
    {
    case West:
        movement_part = make_pair(snake_head.first, snake_head.second - 1);
        break;
    case North:
        movement_part = make_pair(snake_head.first - 1, snake_head.second);
        break;
    case East:
        movement_part = make_pair(snake_head.first, snake_head.second + 1);
        break;
    case South:
        movement_part = make_pair(snake_head.first + 1, snake_head.second);
        break;
    }
    snake_head = movement_part;
    snake_parts.push_back(movement_part);
    food_eaten = snake_head.first == snake_food.first && snake_head.second == snake_food.second;
    if (!food_eaten)
    {
        snake_parts.erase(snake_parts.begin());
    }
}

void Snake::set_snake_food(pair<int, int> snake_food)
{
    this->snake_food = snake_food;
}