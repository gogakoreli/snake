#ifndef _snake_map_h
#define _snake_map_h

#define MAP_WIDTH 20
#define MAP_HEIGHT 20
#define MAP_CHAR ". "
#define MAP_END 30

class SnakeMap
{
  public:
    SnakeMap();
    void redraw();

  private:
    char map_array[MAP_HEIGHT][MAP_WIDTH];
};

#endif