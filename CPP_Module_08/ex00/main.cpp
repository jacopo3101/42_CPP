#include "easyfind.hpp"

int main(void)
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    std::list<int> lis;
    lis.push_back(5);
    lis.push_back(3);
    lis.push_back(6);
    lis.push_back(8);
    std::vector<int>::iterator it1 = easyFind(v, 5);
    std::list<int>::iterator it2 = easyFind(lis, 8);
    std::cout << *it1 << std::endl;
    std::cout << *it2 << std::endl;
    return 0;
}
