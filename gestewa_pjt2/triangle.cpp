#include "triangle.h"

Triangle::Triangle(Point p1, Point p2, Point p3, SDL_Color c)
{
    v1 = p1;
    v2 = p2;
    v3 = p3;
    color = c;
}
