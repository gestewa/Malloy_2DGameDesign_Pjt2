#include "circle.h"
#include <iostream>

Circle::Circle(Point s, int r, SDL_Color c) : center(s), radius(r), color(c) {}

void Circle::Draw(SDL_Renderer *r) const
{
    SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);

    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(r, center.getX() + dx, center.getY() + dy);
            }
        }
    }
}

int Circle::getRadius() const
{
    return radius;
}

std::ostream &operator<<(std::ostream &out, const Circle &c)
{
    return out << "I am a circle, and with high probability, one of low resolution, because my radius is " << c.getRadius();
}