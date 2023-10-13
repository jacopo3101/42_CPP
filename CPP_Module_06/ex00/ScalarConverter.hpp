#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

enum Types{Int, Char, Float, Double, nan, nanf, plus_inf, minus_inf, plus_inff, minus_inff};

class ScalarConverter
{

    private:
        static void printInt(std::string literal);
        static void printChar(std::string literal);
        static void printFloat(std::string literal);
        static void printDouble(std::string literal);
        static int isInt(std::string literal);
        static int isChar(std::string literal);
        static int isFloat(std::string literal);
        static int isDouble(std::string literal);
public:
    static void convert(char *literal);
};