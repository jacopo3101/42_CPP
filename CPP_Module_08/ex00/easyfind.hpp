#include <iterator>
#include <iostream>
#include <vector>
#include <list>

template<typename T>
typename T::const_iterator easyFind(const T &container, int n)
{
    return T.find(n);
}