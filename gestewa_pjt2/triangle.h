#pragma once

#include <SDL2/SDL.h>
#include "point.h"

class Triangle
{
public:
  Triangle(Point v1, Point v2, Point v3, SDL_Color c);
  Triangle(Point v1, int w, int h, SDL_Color c);
  void Draw(SDL_Renderer *) const;

private:
  Point v1;
  Point v2;
  Point v3;
  SDL_Color color;
};