#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "input.h"
#include "snake.h"
#include "snake_map.h"

using namespace std;

Snake snake;
SnakeMap snake_map(snake);

void initialize()
{
    input_init();
    input_enter_off();
}

void start_game()
{
    while (true)
    {
        snake_map.redraw();
        usleep(1000 * 1000);
        snake.validate_direction();
    }
}

int main()
{
    initialize();
    start_game();
    return 0;
}