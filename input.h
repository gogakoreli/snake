#ifndef _input_h
#define _input_h


enum Direction {
    Error = -1,
    West = 0,
    North = 1,
    East = 2,
    South = 3
};

void input_init(void);
void input_enter_off(void);
void input_enter_on(void);
enum Direction get_input(void);

#endif