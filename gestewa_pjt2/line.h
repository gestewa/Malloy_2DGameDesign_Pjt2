#pragma once

#include <SDL2/SDL.h>
#include "point.h"

class Line
{
public:
  Line(Point, Point, SDL_Color);
  void Draw(SDL_Renderer *) const;
  Line(const Line &) = delete;
  Line &operator=(const Line &) = delete;

private:
  Point start;
  Point end;
  SDL_Color color;
};