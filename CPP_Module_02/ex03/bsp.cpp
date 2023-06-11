#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate the vectors representing the edges of the triangle
    Point ab = b - a;
    Point bc = c - b;
    Point ca = a - c;

    // Calculate the vectors from the vertices to the test point
    Point ap = point - a;
    Point bp = point - b;
    Point cp = point - c;

    // Perform the cross product between the vectors
    Fixed crossABP = ab.getX() * bp.getY() - ab.getY() * bp.getX();
    Fixed crossBCP = bc.getX() * cp.getY() - bc.getY() * cp.getX();
    Fixed crossCAP = ca.getX() * ap.getY() - ca.getY() * ap.getX();
    std::cout << crossABP << " " << crossBCP << " " <<crossCAP << " " << std::endl; 

    // Check if the signs of the cross products are all positive or all negative
    bool isInside = (crossABP > Fixed(0) && crossBCP > Fixed(0) && crossCAP > Fixed(0)) ||
                    (crossABP < Fixed(0) && crossBCP < Fixed(0) && crossCAP < Fixed(0));
    return isInside;
}
/*
static double pointDistance(const Point &a, const Point &b)
{
    double tmp = pow(b.getX().toFloat() - a.getX().toFloat(), 2) + pow(b.getY().toFloat() - a.getY().toFloat(), 2);
    tmp = std::sqrt(tmp);
    return tmp; 
}

static int maxSide( Point const &a, Point const &b, Point const &c)
{
    if (roundf(pointDistance(a, b)) == 0 && roundf(pointDistance(a, c)) == 0 && roundf(pointDistance(b, c)) == 0)
        return -1;
    if (pointDistance(a, b) >= pointDistance(a, c))
    {
        if (pointDistance(a, b) >= pointDistance(b, c))
            return 0;
        else
            return 2;
    }
    else if(pointDistance(a, c) >= pointDistance(b, c))
    {
        return 1;
    }
    else
        return 2;
}

static Point midpoint(const Point &a, const Point &b)
{
    return Point((a.getX() + b.getX()) / 2, (a.getY() + b.getY()) / 2);
}

static bool recoursiveBSP( Point const a, Point const b, Point const c, Point const point, bool *res)
{
    if (a == point || b == point || c == point)
    {
        *res = true;
        return true;
    }
    switch (maxSide(a, b, c))
    {
    case 0:
        recoursiveBSP(midpoint(a, b), a, c, point, res);
        recoursiveBSP(midpoint(a, b), b, c, point, res);
        break;
    case 1:
        recoursiveBSP(midpoint(a, c), b, a, point, res);
        recoursiveBSP(midpoint(a, c), b, c, point, res);
        break;
    case 2:
        recoursiveBSP(midpoint(b, c), a, b, point, res);
        recoursiveBSP(midpoint(b, c), a, c, point, res);
        break;
    default:
        break;
    }
    return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool res;
    recoursiveBSP(a, b, c, point, &res);
    return res;
}*/