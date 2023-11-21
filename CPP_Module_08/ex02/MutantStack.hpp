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

    MutantStack& operator=(const MutantStack &other)
    {
        if(other != *this)
            this = other;
        return  *this;
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