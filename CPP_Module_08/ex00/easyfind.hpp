#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template<typename T>
typename T::iterator easyFind(T &container, int n)
{
    return std::find(container.begin(), container.end(), n);
}