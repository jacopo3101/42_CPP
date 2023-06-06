#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    static const int fractBits = 8;
    int fixedPoint;
public:

    Fixed(int fixedPoint);
    Fixed();
    ~Fixed();
    int getRawBits(void);
    void setRawBits(int const raw);
};

#endif