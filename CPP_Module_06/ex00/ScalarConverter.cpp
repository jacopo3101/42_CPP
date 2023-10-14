#include "ScalarConverter.hpp"

void ScalarConverter::convert(char *literal)
{
    std::string strLiteral(literal);
    std::cout << ScalarConverter::isDouble(strLiteral) << std::endl;
    if (ScalarConverter::isDouble(strLiteral))
        ScalarConverter::printDouble(strLiteral);
    else if (ScalarConverter::isFloat(strLiteral))
        ScalarConverter::printFloat(strLiteral);
    else if (ScalarConverter::isInt(strLiteral))
        ScalarConverter::printInt(strLiteral);
    else if (ScalarConverter::isChar(strLiteral))
        ScalarConverter::printChar(strLiteral);
    else
        ScalarConverter::printPseudoLiteral(strLiteral);
}

int ScalarConverter::isInt(std::string literal)
{
    int i = 0;
    while ((long unsigned int)i <= literal.length() && std::isdigit(literal[i]))
        i++;
    if ((long unsigned int)i == literal.length())
        return 1;
    else
        return 0;
}

int ScalarConverter::isFloat(std::string literal)
{
    int i = 0;
    int repeatCount = 0;
    while ((long unsigned int)i <= literal.length() - 1 && (std::isdigit(literal[i]) || literal[i] == '.'))
    {
        if (literal[i] == '.')
            repeatCount++;
        i++;
    }
    if ((long unsigned int)i == literal.length() - 1 && literal[0] != '.' && literal[literal.length() - 1] != '.' 
        && literal.find('.') && literal[literal.length()] != 'f' && repeatCount == 1)
        return 1;
    else
        return 0;
}

int ScalarConverter::isDouble(std::string literal)
{
    int i = 0;
    int repeatCount = 0;
    while ((long unsigned int)i <= literal.length() && (std::isdigit(literal[i]) || literal[i] == '.'))
    {
        if (literal[i] == '.')
            repeatCount++;
        i++;
    }
    if ((long unsigned int)i == literal.length() && literal[0] != '.' && literal[literal.length() - 1] != '.' 
        && literal.find('.') && repeatCount == 1)
        return 1;
    else
        return 0;
}

int ScalarConverter::isChar(std::string literal)
{
    if (!(std::isdigit(literal[0])) && literal.length() == 1)
        return 1;
    else
        return 0;
}

void ScalarConverter::printInt(std::string literal)
{
    int n = std::atoi(literal.c_str());
    std::cout << "char : ";
    if ( std::isprint(n))
        std::cout << static_cast<char>(n) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}