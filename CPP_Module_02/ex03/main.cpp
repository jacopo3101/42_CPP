#include "Point.hpp"

int main( void )
{
	Point a(5.0f, 5.0f);
	Point b(3.0f, 2.0f);
	Point c(3.0f, 6.0f);

	Point point(7.8f, 4.0f);

	std::cout  << "res = "<< bsp(a, b, c, point) << std::endl; 

	std::cout << c.getX() << " - " << c.getY() << std::endl; 

	return 0;
}