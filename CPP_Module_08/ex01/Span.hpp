#pragma once
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <limits>

class Span
{
private:
    std::vector<int> numVector;
    unsigned int maxN;
public:
    Span(unsigned int n);
    Span();
    Span(Span const &other);
    unsigned int getMaxN()const;
    const std::vector<int> &getVector() const;
    void addNumber(int n);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();
    void print();
    Span& operator=(const Span &other);
    ~Span();

    class MaxElementException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class SpanFailedEXception : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

// class IndexOutOfBoundException : public std::exception
//     {
//     public:
//         virtual const char *what() const throw()
//         {
//             return "Index out of bound!";
//         }
//     };