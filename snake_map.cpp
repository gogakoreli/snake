#include "snake_map.h"
#include <pthread.h>
#include <iostream>

using namespace std;

SnakeMap::SnakeMap(void)
{
}

void SnakeMap::redraw(void)
{
    for (int i = 0; i < MAP_END; i++)
    {
        cout << endl;
    }
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            cout << MAP_CHAR;
        }
        cout << endl;
    }
}