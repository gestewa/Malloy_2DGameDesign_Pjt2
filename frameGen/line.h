#pragma once

#include <SDL.h>
#include "point.h"

class Line
{
public:
  Line(Point, Point, SDL_Color);
  Draw(SDL_Renderer *);

private:
  Point start;
  Point end;
  SDL_Color color;
};