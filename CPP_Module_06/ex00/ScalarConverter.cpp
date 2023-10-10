#include "ScalarConverter.hpp"

void ScalarConverter::convert(char *literal)
{
    std::string strLiteral(literal);
    std::cout << std::stod(strLiteral) << " " << std::stof(strLiteral) <<std::endl;
    
}