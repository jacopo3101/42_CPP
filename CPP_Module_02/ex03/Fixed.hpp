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
    bool operator==(const Fixed &other);
    bool operator!=(const Fixed &other);
    bool operator>(const Fixed &other) const;
    bool operator>=(const Fixed &other);
    bool operator<(const Fixed &other) const;
    bool operator<=(const Fixed &other);
    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif