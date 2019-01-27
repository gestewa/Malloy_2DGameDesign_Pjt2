#pragma once

#include <SDL2/SDL.h>

class Point
{
public:
  Point();
  Point(int, int);
  int getX() const;
  int getY() const;

private:
  SDL_Point point;
};