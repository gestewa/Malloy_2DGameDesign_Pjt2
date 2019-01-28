#include "line.h"

Line::Line(Point s, Point f, SDL_Color c)
{
    start = s;
    end = f;
    color = c;
}

void Line::Draw(SDL_Renderer *r) const
{
    SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(r, start.getX(), start.getY(), end.getX(), end.getY());
}