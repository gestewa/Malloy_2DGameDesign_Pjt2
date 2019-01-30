#include "point.h"

Point::Point() : point{0, 0} {}

Point::Point(int x, int y) : point{x, y} {}

int Point::getX() const
{
    return point.x;
}

int Point::getY() const
{
    return point.y;
}