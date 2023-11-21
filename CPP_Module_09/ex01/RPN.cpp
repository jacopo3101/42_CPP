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

int RPN::executeOperation(int a, int b, char _operator)
{
    switch (_operator)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        break;
    }
    return -1;
}

void RPN::singleOperation()
{
	int tmp;
	tmp = valueStack.top();
    valueStack.pop();
    tmp = RPN::executeOperation(valueStack.top(), tmp, operationStack.top());
    valueStack.pop();
    operationStack.pop();
	valueStack.push(tmp);
}

void RPN::doubleOperation()
{
	int valTmp1, valTmp2;
	char operation1, operation2;
	valTmp1 = valueStack.top();
	valueStack.pop();
	valTmp2 = valueStack.top();
	valueStack.pop();
	operation1 = operationStack.top();
	operationStack.pop();
	operation2 = operationStack.top();
	operationStack.pop();
	if (operation2 == '*' || operation2 == '/')
	{
		valueStack.push(RPN::executeOperation(valTmp2, valTmp1, operation2));
		valTmp1 = valueStack.top();
		valueStack.pop();
		valTmp2 = valueStack.top();
		valueStack.pop();
		valueStack.push(RPN::executeOperation(valTmp2, valTmp1, operation1));
	}
	else
	{
		valueStack.push(RPN::executeOperation(valueStack.top(), valTmp2, operationStack.top()));
		operationStack.pop();
		valTmp2 = valueStack.top();
		valueStack.pop();
		valueStack.push(RPN::executeOperation(valTmp1, valTmp2, operationStack.top()));
	}
}

void RPN::EvaluateExpression(std::string token)
{
	int status;
    try
    {
        tokenizeStart(const_cast<char *>(token.c_str()));
    }
    catch(const RPN::BadExpressionFormatException& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    RPN::singleOperation();
    try
    {
        while (!expression.empty())
        {

            status = tokenize(const_cast<char *>(token.c_str()));

			
			if (status == 1)
			    RPN::singleOperation();
			else
				RPN::doubleOperation();
			
        }
        
    }
    catch(const RPN::BadExpressionFormatException& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
	std::cout << valueStack.top() << std::endl;
}

void RPN::tokenizeStart(char *token)
{
    char *tmp;
    tmp = std::strtok(const_cast<char *>(expression.c_str()), token);
    valueStack.push(tokenToInt(tmp));
    if(valueStack.top() == -1)
        throw RPN::BadExpressionFormatException();
    tmp = std::strtok(NULL, token);

    valueStack.push(tokenToInt(tmp));
    if(valueStack.top() == -1)
        throw RPN::BadExpressionFormatException();
    tmp = std::strtok(NULL, token);
    operationStack.push(tokenToOperation(tmp));
    if(valueStack.top() == -1)
        throw RPN::BadExpressionFormatException();
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
    if (tmpVal == -1 && tokenToOperation(tmp) != -1)
    {
        operationStack.push(tokenToOperation(tmp));
        tmp = std::strtok(NULL, "\0");
		if (tmp == NULL)
		{
			expression.clear();
			return 1;
		}	
		expression = tmp;
        if (operationStack.top() == -1)
            throw RPN::BadExpressionFormatException();
        else 
            return 1;
    }
    else if (tmpVal != -1)
    {
		valueStack.push(tokenToInt(tmp));
		if (valueStack.top() == -1)
            throw RPN::BadExpressionFormatException();
        tmp = std::strtok(NULL, token);
        operationStack.push(tokenToOperation(tmp));
        if (operationStack.top() == -1)
            throw RPN::BadExpressionFormatException();
        tmp = std::strtok(NULL, token);
        operationStack.push(tokenToOperation(tmp));
        tmp = std::strtok(NULL, "\0");
		if (tmp == NULL)
		{
			expression.clear();
			return 0;
		}
		expression = tmp;
        if (operationStack.top() == -1)
            throw RPN::BadExpressionFormatException();
        else 
            return 0;
    }
	return -1;
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
        throw RPN::BadExpressionFormatException();
    std::string n(str);
    if (n.size() != 1)
        throw RPN::BadExpressionFormatException();
    if (str[0] == '*' || str[0] == '+' || str[0] == '/' || str[0] == '-')
        return str[0];
    throw RPN::BadExpressionFormatException();
    return -1;
}

const char * RPN::BadExpressionFormatException::what() const throw()
{
    return "expression evaluation failed!";
}

RPN::~RPN(){}