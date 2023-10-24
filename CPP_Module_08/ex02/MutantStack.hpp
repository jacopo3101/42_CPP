#pragma once
#include <iterator>
#include <stack>
#include <deque>
#include <iterator>

template<typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T>
{
public:
    MutantStack(){}

    MutantStack(const MutantStack &other)
    {
        *this = other;
    }

    ~MutantStack(){}

    typedef typename container::iterator iterator;
    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }
};