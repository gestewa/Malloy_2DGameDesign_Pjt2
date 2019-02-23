#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include "point.h"

class Circle
{
public:
  Circle(Point s, int r, SDL_Color c);
  void Draw(SDL_Renderer *) const;
  int getRadius() const;

private:
  Point center;
  int radius;
  SDL_Color color;
};
std::ostream &operator<<(std::ostream &, const Circle &);
