#include <SDL2/SDL.h>

class Point
{
  public:
    Point();
    Point(int x, int y);
    int getX() const;
    int getY() const;

  private:
    SDL_Point point;
    freind class Circle;
    freind class Rectangle;
    freind class Triangle;
    freind class Line;
};