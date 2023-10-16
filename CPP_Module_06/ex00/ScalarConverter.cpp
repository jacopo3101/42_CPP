#include "ScalarConverter.hpp"

void ScalarConverter::convert(char *literal)
{
    std::string strLiteral(literal);
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
    std::cout << "int : " << n << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(n) << std::endl;
}

void ScalarConverter::printChar(std::string literal)
{
    char c = literal[0];
    std::cout << "char : ";
    if ( std::isprint(c))
        std::cout << c << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printFloat(std::string literal)
{
    std::istringstream ss(literal);
    float f;
    ss >> f;
    std::cout << "char : ";
    if ( std::isprint(static_cast<char>(f)))
        std::cout << static_cast<char>(f) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int : " << static_cast<int>(f) << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printDouble(std::string literal)
{
    std::istringstream ss(literal);
    double d;
    ss >> d;
    std::cout << "char : ";
    if ( std::isprint(static_cast<char>(d)))
        std::cout << static_cast<char>(d) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int : " << static_cast<int>(d) << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double : " << d << std::endl;
}

void ScalarConverter::printPseudoLiteral(std::string literal)
{
    if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
    {
        std::cout << "char: impossible" << std::endl
            << "int: impossible" << std::endl
            << "float: nanf" << std::endl
            << "double: nan" << std::endl;
    }
    else if (literal.compare("+inff") == 0 || literal.compare("+inf") == 0)
    {
        std::cout << "char: " << std::numeric_limits<char>::max() << std::endl
            << "int: " << std::numeric_limits<int>::max() << std::endl
            << "float: " << std::numeric_limits<float>::max() << "f" << std::endl
            << "double: " << std::numeric_limits<double>::max() << std::endl;
    }
    else if (literal.compare("-inff") == 0 || literal.compare("-inf") == 0)
    {
        std::cout << "char: "<< std::numeric_limits<char>::min() << std::endl
            << "int: " << std::numeric_limits<int>::min() << std::endl
            << "float: " << std::numeric_limits<float>::min() << "f" << std::endl
            << "double: " << std::numeric_limits<double>::min() << std::endl;
    }
    
}