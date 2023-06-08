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

    Fixed(Fixed &fixed);
    Fixed(const int n);
    Fixed(const float n);
    Fixed();
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed& operator=(Fixed &other);
};

#endif