#include "circle.h"

Circle::Circle(Point s, int r, SDL_Color c)
{
    center = s;
    radius = r;
    color = c;
}

Circle::Draw(SDL_Renderer *r)
{
    SDL_SetRendererDrawColor(r, color.r, color.g, color.b, color.a);

    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, center.x + dx, center.y + dy);
            }
        }
    }
}