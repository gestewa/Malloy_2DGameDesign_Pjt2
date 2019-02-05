#pragma once

#include <SDL2/SDL.h>
#include "point.h"

class Triangle
{
public:
  Triangle(Point, Point, Point, SDL_Color);
  void Draw(SDL_Renderer *) const;
  Triangle(const Triangle &) = delete;
  Triangle &operator=(const Triangle &) = delete;

private:
  Point v1;
  Point v2;
  Point v3;
  SDL_Color color;
};