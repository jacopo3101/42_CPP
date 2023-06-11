#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float _x, const float _y) : x(_x), y(_y) {}

Point::Point(const Fixed _x, const Fixed _y) : x(_x), y(_y) {}

Point::Point(const Point &point) : x(point.x), y(point.y) {}

Point& Point::operator=(const Point &other)
{
    if (this != &other) {}
    return *this;
}

bool Point::operator==(const Point &other) const
{
    if (other.getX() == this->x && other.getY() == this->y)
        return true;
    else
        return false;
}

Point Point::operator-(const Point &other) const
{
    Fixed X(this->getX() - other.x);
    Fixed Y(this->getY() - other.y);
    return Point(X, Y);
}

Point::~Point(){}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}