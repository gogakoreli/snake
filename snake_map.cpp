#include "snake_map.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

SnakeMap::SnakeMap(Snake *snake)
{
    this->snake = snake;
    clear_map(this->map_array);
}

void SnakeMap::redraw(void)
{
    clear_map(this->map_array);
    for (int i = 0; i < MAP_END; i++)
    {
        cout << endl;
    }
    vector<pair<int, int>> snake_parts = snake->snake_parts;
    for (int i = 0; i < snake_parts.size(); i++)
    {
        pair<int, int> tmp = snake_parts[i];
        map_array[tmp.first][tmp.second] = SNAKE_CHAR;
    }
    update_snake_head(map_array, snake);
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            cout << map_array[i][j] << " ";
        }
        cout << endl;
    }
}

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            map_array[i][j] = MAP_CHAR;
        }
    }
}

void update_snake_head(char map_array[MAP_HEIGHT][MAP_WIDTH], Snake *snake)
{
    char snake_head_char = SNAKE_CHAR;
    enum Direction direction = snake->get_direction();
    switch (direction)
    {
    case West:
        snake_head_char = SNAKE_HEAD_WEST;
        break;
    case North:
        snake_head_char = SNAKE_HEAD_NORTH;
        break;
    case East:
        snake_head_char = SNAKE_HEAD_EAST;
        break;
    case South:
        snake_head_char = SNAKE_HEAD_SOUTH;
        break;
    }
    pair<int, int> snake_head = snake->snake_head;
    map_array[snake_head.first][snake_head.second] = snake_head_char;
}