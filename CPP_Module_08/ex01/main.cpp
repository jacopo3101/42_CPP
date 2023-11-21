# include "Span.hpp"

int randomNumber()
{
    return rand() % 1000;
}

int main()
{
    Span s(5);
    s.addNumber(13);
    s.addNumber(4);
    s.addNumber(15);
    s.addNumber(9);
    s.addNumber(8);
    try
    {
        s.addNumber(6);
    }
    catch(const Span::MaxElementException& e)
    {
        std::cerr << e.what() << '\n';
    }
    s.print();
    std::cout << s.longestSpan() << std::endl;
    std::cout << s.shortestSpan() << std::endl;

    Span s1(10001);
    s1.addNumber(13);
    try
    {
        std::cout << s1.longestSpan() << std::endl;
    }
    catch(const Span::SpanFailedEXception& e)
    {
        std::cerr << e.what() << '\n';
    }
    srand(time(NULL));
    std::vector<int> tmp(10000);
    std::generate(tmp.begin(), tmp.end(), randomNumber);
    s1.addNumber(tmp.begin(), tmp.end());
    s1.print();
    try
    {
        s1.addNumber(4);
    }
    catch(const Span::MaxElementException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
