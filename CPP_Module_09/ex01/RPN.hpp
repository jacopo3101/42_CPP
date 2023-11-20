#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>

class RPN
{
private:
    std::string expression;
    std::stack<int> valueStack;
    std::stack<char> operationStack;
    int tokenToInt(char *str);
    int tokenToOperation(char *str);
    void tokenizeStart(char *token);
    int tokenize(char *token);
    void singleOperation();
    void doubleOperation();
    int executeOperation(int a, int b, char _operator);

    RPN();
public:
    void EvaluateExpression(std::string token); 
    RPN(std::string str);
    RPN(const RPN &other);
    ~RPN();
    class BadExpressionFormatException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};