#pragma once

#include <SDL.h>
#include "point.h"

class Triangle
{
  public:
    Triangle(Point v1, Point v2, Point v3, SDL_Color c);
    Triangle(Point v1, int w, int h, SDL_Color c);
    Draw(SDL_Renderer *);

  private:
    Point v1;
    Point v2;
    Point v3;
    SDL_Color color;
};