#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Point ab = b - a;
    Point bc = c - b;
    Point ca = a - c;

    Point ap = point - a;
    Point bp = point - b;
    Point cp = point - c;

    Fixed crossABP = ab.getX() * bp.getY() - ab.getY() * bp.getX();
    Fixed crossBCP = bc.getX() * cp.getY() - bc.getY() * cp.getX();
    Fixed crossCAP = ca.getX() * ap.getY() - ca.getY() * ap.getX();

    return (crossABP > Fixed(0) && crossBCP > Fixed(0) && crossCAP > Fixed(0)) ||
                (crossABP < Fixed(0) && crossBCP < Fixed(0) && crossCAP < Fixed(0));
}