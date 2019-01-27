#include "line.h"

Line::Line(Point s, Point f, SDL_Color c)
{
    start = s;
    end = f;
    color = c;
}

Line::Draw(SDL_Renderer *r)
{
    SDL_SetRendererDrawColor(r, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(r, start.x, start.y, end.x, end.y);
}