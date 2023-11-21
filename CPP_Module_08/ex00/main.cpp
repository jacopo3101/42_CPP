#include "easyfind.hpp"

int main(void)
{
    std::vector<int> v;
    v.push_back(0);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    std::list<int> lis;
    lis.push_back(5);
    lis.push_back(3);
    lis.push_back(6);
    lis.push_back(8);
    std::vector<int>::iterator it1 = easyFind(v, 0);
    std::list<int>::iterator it2 = easyFind(lis, 8);
    std::list<int>::iterator it3 = easyFind(lis, 65416);
    if (it1 != v.end())
        std::cout << "Find: "<< *it1 << std::endl;
    if (it2 != lis.end())
    	std::cout << "Find: " << *it2 << std::endl;
    if (it3 != lis.end())
    	std::cout << "Find: " << *it3 << std::endl;
    return 0;
}
