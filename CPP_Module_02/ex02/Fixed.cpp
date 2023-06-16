#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPoint = 0;
}

Fixed::Fixed(const int n)
{
	fixedPoint = n * (1 << fractBits);
}

Fixed::Fixed(const float n)
{
	fixedPoint = roundf(n * (1 << fractBits));
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->fixedPoint = other.fixedPoint;
	return *this;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

int Fixed::getRawBits(void) const
{
	return fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)fixedPoint / (float)(1 << fractBits));
}

int Fixed::toInt(void) const
{
	return (roundf(this->toFloat()));
}

Fixed::~Fixed()
{}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator==(const Fixed &other)
{
	if (this->toFloat() == other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed &other)
{
	if (this->toFloat() != other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->toFloat() > other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed &other)
{
	if (this->toFloat() >= other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->toFloat() < other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed &other)
{
	if (this->toFloat() <= other.toFloat())
		return true;
	else
		return false;
}

Fixed Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(this->toFloat());
	this->fixedPoint++;
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(this->toFloat());
	this->fixedPoint--;
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}