#include "PmergeMe.hpp"
#include <sstream>

int strToInt(char const *str)
{
    int res;
    std::string test(str);
    for (size_t i = 0; i < test.size(); i++)
    {
        if (!std::isdigit(test[i]))
            return -1;
    }
    
    std::stringstream ss;  
    ss << str;  
    ss >> res;
    
    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<unsigned int> vec;
    std::list<unsigned int> list;
    PmergeMe merge;
    int tmp = 0;
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            tmp = strToInt(argv[i]);
            if (tmp < 0 )
            {
                std::cout << "Error!" << std::endl;
                return -1;
            }
            else
            {
                vec.push_back(tmp);
                list.push_back(tmp);
            }
        }
        merge.sortVector(vec);
        merge.sortList(list);
    }
    return 0;
}
