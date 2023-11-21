#include "Span.hpp"

Span::Span(unsigned int n) : maxN(n)
{}

Span::Span() : maxN(0)
{}

Span::Span(Span const &other) : maxN(other.getMaxN())
{
    this->numVector = other.getVector();
}

unsigned int Span::getMaxN() const
{
    return maxN;
}

const std::vector<int> &Span::getVector() const
{
    return numVector;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        maxN = other.getMaxN();
        numVector = other.getVector();
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (numVector.size() >= maxN)
        throw Span::MaxElementException();
    numVector.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    numVector.insert(numVector.end(), begin, end);
}
int Span::longestSpan()
{
    if (numVector.size() < 2)
        throw Span::SpanFailedEXception();
    int n = 0;
    for (size_t i = 0; i < numVector.size() - 1; i++)
    {
        if (std::abs(numVector[i] - numVector[i + 1]) > n)
            n = std::abs(numVector[i] - numVector[i + 1]);
    }
    return n;
}

int Span::shortestSpan()
{
    if (numVector.size() < 2)
        throw Span::SpanFailedEXception();
    int n = std::numeric_limits<int>::max();
    for (size_t i = 0; i < numVector.size() - 1; i++)
    {
        if (std::abs(numVector[i] - numVector[i + 1]) < n)
            n = std::abs(numVector[i] - numVector[i + 1]);
    }
    return n;
}

Span::~Span()
{}

const char *Span::MaxElementException::what() const throw()
{
    return "Max element limit reached";
}

const char *Span::SpanFailedEXception::what() const throw()
{
    return "Too low elements on the list";
}
void Span::print()
{
    for (std::vector<int>::iterator it=numVector.begin(); it!=numVector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}