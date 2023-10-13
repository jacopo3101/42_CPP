#include "ScalarConverter.hpp"

void ScalarConverter::convert(char *literal)
{
    std::string strLiteral(literal);
    Types types;
    std::cout << ScalarConverter::isDouble(strLiteral) << std::endl;
    if (ScalarConverter::isDouble(strLiteral))
        types = Double;
    if (ScalarConverter::isFloat(strLiteral))
        types = Float;
    if (ScalarConverter::isInt(strLiteral))
        types = Int;
    if (ScalarConverter::isChar(strLiteral))
        types = Char;
    
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