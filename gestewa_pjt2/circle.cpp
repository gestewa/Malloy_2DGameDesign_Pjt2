#include "circle.h"

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