#include <SDL.h>
#include "point.h"

class Rectangle
{
public:
  Rectangle(Point, int, SDL_Color);
  Rectangle(Point, int, int, SDL_Color);
  Draw(SDL_Renderer *);

private:
  SDL_Rect shape;
  SDL_Color color;
};