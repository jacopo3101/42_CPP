#include "RPN.hpp"

RPN::RPN(std::string str) : expression(str)
{}

RPN::RPN()
{}

RPN::RPN(const RPN &other)
{
    expression = other.expression;
    valueStack = other.valueStack;
    operationStack = other.operationStack;
}

void RPN::EvaluateExpression(std::string token)
{
    try
    {
        tokenizeStart(const_cast<char *>(token.c_str()));
    }
    catch(const RPN::BadExpressionFormatException& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    try
    {
        while (expression.c_str() != NULL)
        {
            std::cout << "2" << expression << std::endl;
            tokenize(const_cast<char *>(token.c_str()));
        }
        
    }
    catch(const RPN::BadExpressionFormatException& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    //std::cout << valueStack.top();
    //valueStack.pop();
    //std::cout << " " << valueStack.top() << " " << operationStack.top() << std::endl;
}

void RPN::tokenizeStart(char *token)
{
    char *tmp;
    tmp = std::strtok(const_cast<char *>(expression.c_str()), token);
    valueStack.push(tokenToInt(tmp));
    if(valueStack.top() == -1)
        throw RPN::BadExpressionFormatException();
    tmp = std::strtok(NULL, token);
    std::cout << "tmp : " << tmp << std::endl;

    valueStack.push(tokenToInt(tmp));
    if(valueStack.top() == -1)
        throw RPN::BadExpressionFormatException();
    tmp = std::strtok(NULL, token);
    operationStack.push(tokenToOperation(tmp));
    if(valueStack.top() == -1)
        throw RPN::BadExpressionFormatException();
    std::cout << "exp : "<< expression << std::endl;
    expression = std::strtok(NULL, "\0");
}

int RPN::tokenize(char *token)
{
    char *tmp;
    int tmpVal;
    tmp = std::strtok(const_cast<char *>(expression.c_str()), token);
    valueStack.push(tokenToInt(tmp));
    if(valueStack.top() == -1)
        throw RPN::BadExpressionFormatException();
    tmp = std::strtok(NULL, token);
    tmpVal = tokenToInt(tmp);
    if (tmpVal == -1)
    {
        operationStack.push(tokenToOperation(tmp));
        if (operationStack.top() == -1)
            throw RPN::BadExpressionFormatException();
        else 
            return 1;
    }
    else
    {
        operationStack.push(tokenToOperation(tmp));
        if (operationStack.top() == -1)
            throw RPN::BadExpressionFormatException();
        else
            return 0;
        operationStack.push(tokenToOperation(tmp));
        if (operationStack.top() == -1)
            throw RPN::BadExpressionFormatException();
        else 
            return 0;
    }
}

int RPN::tokenToInt(char *str)
{
    if (str == NULL)
        return -1;
    std::string n(str);
    for (size_t i = 0; i < n.size(); i++)
    {
        if (!std::isdigit(n[i]))
            return -1;
    }
    return atoi(str);
}

int RPN::tokenToOperation(char *str)
{
    if (str == NULL)
        return -1;
    std::string n(str);
    if (n.size() != 1)
        return 1;
    if (str[0] == '*' || str[0] == '+' || str[0] == '/' || str[0] == '-')
        return str[0];
    return -1;
}

const char * RPN::BadExpressionFormatException::what() const throw()
{
    return "expression evaluation failed!";
}

RPN::~RPN(){}