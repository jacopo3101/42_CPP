#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        RPN exp(argv[1]);
        exp.EvaluateExpression(" ");
    }
    return 0;
}
