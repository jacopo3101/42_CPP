#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float _x, const float _y) : x(_x), y(_y) {}

Point::Point(Point &point) : x(point.x), y(point.y) {}

Point& Point::operator=(const Point &other)
{
    if (this != &other)
    {
    }
    return *this;
}
