#include "easyfind.hpp"

int main(void)
{
    std::vector<int> v = {2,3,5,7,6};
    std::list<int> lis = {2,3,5,7,6};
    typename std::vector<int>::const_iterator it = easyFind(lis, 5);
    std::cout << *it << std::endl;
    return 0;
}
