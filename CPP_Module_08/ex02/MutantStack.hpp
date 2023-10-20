#pragma once
#include <iterator>
#include <iostream>
#include <list>

template<typename T>
class MutantStack
{
private:
    std::list<T> list;
public:
    MutantStack();
    ~MutantStack();
    bool empty() const;
    void pop();
    void push(const T &val)
    unsigned int size() const;
    T &top();
};