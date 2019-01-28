#pragma once

#include <SDL2/SDL.h>
#include "point.h"

class Circle
{
public:
  Circle(Point s, int r, SDL_Color c);
  void Draw(SDL_Renderer *) const;

private:
  Point center;
  int radius;
  SDL_Color color;
};