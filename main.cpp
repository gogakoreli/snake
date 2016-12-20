#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "input.h"
#include "snake.h"
#include <condition_variable>

using namespace std;

Snake snake;

void initialize()
{
    input_init();
    input_enter_off();
}

void start_game()
{
    while (true)
    {
        cout << "Snake Direction is:" << snake.get_direction() << endl;
        cout << "now sleeping" << endl;
        usleep(1000 * 1000);
    }
}

int main()
{
    initialize();
    start_game();
    return 0;
}