#include "rectangle.h"

Rectangle::Rectangle(Point s, int w, SDL_Color c)
{
    shape.x = s.getX();
    shape.y = s.getY();
    shape.w = w;
    shape.h = w;
    color = c;
}

Rectangle::Rectangle(Point s, int w, int h, SDL_Color c)
{
    shape.x = s.getX();
    shape.y = s.getY();
    shape.w = w;
    shape.h = h;
    color = c;
}

void Rectangle::Draw(SDL_Renderer *r) const
{
    SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(r, &shape);
}