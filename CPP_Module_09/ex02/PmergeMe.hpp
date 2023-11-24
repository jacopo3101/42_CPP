#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <sys/time.h>
#include <ctime>

# define MICROSECOND 100000

# define GET_DURATION(start) static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND
class PmergeMe
{
public:
    PmergeMe(void);
    PmergeMe(PmergeMe const &other);
    ~PmergeMe();
    void printVector(std::vector<unsigned int> vec);
    void printList(std::list<unsigned int> list);
    void sortVector(std::vector<unsigned int> vec);
    std::vector<unsigned int> recursiveVectorMerge(std::vector<unsigned int> vec);
    std::vector<unsigned int> vecMerge(std::vector<unsigned int> left, std::vector<unsigned int> right);
    void sortList(std::list<unsigned int> list);
    std::list<unsigned int> recursiveListMerge(std::list<unsigned int> vec);
    std::list<unsigned int> listMerge(std::list<unsigned int> left, std::list<unsigned int> right);
};