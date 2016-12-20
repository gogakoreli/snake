#include "snake_map.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

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
        // cout << "snake at:" << tmp.first << " " << tmp.second << endl;
    }
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            cout << map_array[i][j] << " ";
        }
        cout << endl;
    }
}