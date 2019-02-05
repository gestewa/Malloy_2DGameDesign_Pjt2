#pragma once

#include <SDL2/SDL.h>
#include "point.h"

class Rectangle
{
public:
  Rectangle(Point, int, SDL_Color);
  Rectangle(Point, int, int, SDL_Color);
  void Draw(SDL_Renderer *) const;
  Rectangle(const Rectangle &) = delete;
  Rectangle &operator=(const Rectangle &) = delete;

private:
  SDL_Rect shape;
  SDL_Color color;
};