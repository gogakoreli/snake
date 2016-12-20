#include "input.h"
#include <termios.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>

using namespace std;

struct termios t;
sem_t input_sema;

void input_enter_off()
{
    tcgetattr(STDIN_FILENO, &t);          //get the current terminal I/O structure
    t.c_lflag &= ~ICANON;                 //Manipulate the flag bits to do what you want it to do
    tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
}

void input_enter_on()
{
    tcgetattr(STDIN_FILENO, &t);          //get the current terminal I/O structure
    t.c_lflag |= ICANON;                  //Manipulate the flag bits to do what you want it to do
    tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
}

enum Direction get_input()
{
    enum Direction result = East;
    char user_input = getchar();
    switch (user_input)
    {
    case 'a':
        result = West;
        break;
    case 'w':
        result = North;
        break;
    case 'd':
        result = East;
        break;
    case 's':
        result = South;
        break;
    default:
        result = Error;
        cout << "Incorrect button clicked(" << user_input << ")" << endl;
        break;
    }
    return result;
}

void input_init()
{
    sem_init(&input_sema, 0, 1);
}