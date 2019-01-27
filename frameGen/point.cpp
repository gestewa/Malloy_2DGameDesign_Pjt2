#include "point.h"

Point::Point()
{
    point.x = 0;
    point.y = 0;
}

Point::Point(int x, int y)
{
    point.x = x;
    point.y = y;
}

int Point::getX() const
{
    return point.x;
}

int Point::getY() const
{
    return point.y;
}