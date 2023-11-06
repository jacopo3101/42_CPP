#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <iomanip>
#include <sstream>

class ScalarConverter
{
private:
    static void printInt(std::string literal);
    static void printChar(std::string literal);
    static void printFloat(std::string literal);
    static void printDouble(std::string literal);
    static void printPseudoLiteral(std::string literal);
    static int isInt(std::string literal);
    static int isChar(std::string literal);
    static int isFloat(std::string literal);
    static int isDouble(std::string literal);
    ScalarConverter();
public:
    static void convert(char *literal);
};