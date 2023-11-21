#include "MutantStack.hpp"
#include <iostream>
#include <list>
int main()
{
    std::cout << "Mutant stack :" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout <<"top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout<<"top : " << mstack.top() << std::endl;

    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    std::cout<<"top : " << mstack.top() << std::endl;

    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "---------------------------------------" << std::endl << "STL List :" << std::endl;

    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout <<"top : " << list.back() << std::endl;
    list.pop_back();
    std::cout<<"top : " << list.back() << std::endl;

    std::cout << list.size() << std::endl;
    list.push_back(3);
    std::cout<<"top : " << list.back() << std::endl;

    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);
    std::list<int>::iterator list_it = list.begin();
    std::list<int>::iterator list_ite = list.end();
    ++list_it;
    --list_it;
    while (list_it != list_ite)
    {
        std::cout << *list_it << std::endl;
        ++list_it;
    }
    std::list<int> s1(list);
    return 0;
}
