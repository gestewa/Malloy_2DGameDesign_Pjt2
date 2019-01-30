/*
    Algorithms based off of http://www.sunshine2k.de/coding/java/TriangleRasterization/TriangleRasterization.html
*/

#include "triangle.h"
#include <vector>
#include <utility>
#include <algorithm>

bool sortbyfir(const std::pair<int, Point> &a,
               const std::pair<int, Point> &b)
{
    return (a.first <= b.first);
}

std::vector<std::pair<int, Point>> getV(Point p1, Point p2, Point p3)
{ // Sort the incoming points according to y-coordinate
    std::vector<std::pair<int, Point>> v;
    v.push_back(std::make_pair(p1.getY(), p1));
    v.push_back(std::make_pair(p2.getY(), p2));
    v.push_back(std::make_pair(p3.getY(), p3));

    std::sort(v.begin(), v.end(), sortbyfir);
    return v;
}

Triangle::Triangle(Point p1, Point p2, Point p3, SDL_Color c) : v1(getV(p1, p2, p3)[2].second), v2(getV(p1, p2, p3)[1].second), v3(getV(p1, p2, p3)[0].second), color(c) {}

// cross product x1 y1 x2 y2 = x1*y2-x2*y1
int crossProduct(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - x2 * y1;
}
int crossProduct(Point p1, Point p2)
{
    return p1.getX() * p2.getY() - p2.getX() * p1.getY();
}

void Triangle::Draw(SDL_Renderer *r) const
{
    SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);

    SDL_RenderDrawLine(r, v1.getX(), v1.getY(), v2.getX(), v2.getY());
    SDL_RenderDrawLine(r, v1.getX(), v1.getY(), v3.getX(), v3.getY());
    SDL_RenderDrawLine(r, v2.getX(), v2.getY(), v3.getX(), v3.getY());

    /* get the bounding box of the triangle */
    int maxX = std::max(v1.getX(), std::max(v2.getX(), v3.getX()));
    int minX = std::min(v1.getX(), std::min(v2.getX(), v3.getX()));
    int maxY = std::max(v1.getY(), std::max(v2.getY(), v3.getY()));
    int minY = std::min(v1.getY(), std::min(v2.getY(), v3.getY()));

    /* spanning vectors of edge (v1,v2) and (v1,v3) */
    Point vs1 = Point(v2.getX() - v1.getX(), v2.getY() - v1.getY());
    Point vs2 = Point(v3.getX() - v1.getX(), v3.getY() - v1.getY());

    for (int x = minX; x <= maxX; x++)
    {
        for (int y = minY; y <= maxY; y++)
        {
            Point q = Point(x - v1.getX(), y - v1.getY());

            float s = (float)crossProduct(q, vs2) / crossProduct(vs1, vs2);
            float t = (float)crossProduct(vs1, q) / crossProduct(vs1, vs2);

            if ((s >= 0) && (t >= 0) && (s + t <= 1))
            { /* fill triangle */
                SDL_RenderDrawPoint(r, x, y);
            }
        }
    }
}