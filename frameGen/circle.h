#pragma once

#include <SDL.h>
#include "point.h"

class Circle
{
public:
  Circle(Point s, int r, SDL_Color c);
  Draw(SDL_Renderer *);

private:
  Point center;
  int radius;
  SDL_Color color;
};