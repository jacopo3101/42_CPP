#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <string>
class Fixed
{
private:
    static const int fractBits = 8;
    int fixedPoint;
public:

    Fixed(const Fixed &fixed);
    Fixed(const int n);
    Fixed(const float n);
    Fixed();
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
    Fixed& operator=(const Fixed &other);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif