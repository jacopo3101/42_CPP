#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &other)
{
    *this = other;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printVector(std::vector<unsigned int> vec)
{
    for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printList(std::list<unsigned int> list)
{
    for (std::list<unsigned int>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortVector(std::vector<unsigned int> vec)
{
    // Call the function whose execution time needs to be measured
    std::cout << "before: ";
    printVector(vec);
    std::cout << std::endl;


    std::clock_t start = std::clock();
    vec = recursiveVectorMerge(vec);
    double time_taken = GET_DURATION(start);

    std::cout << "after: ";
    printVector(vec);
    std::cout << std::endl;

    // Output the execution time in microseconds
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time_taken << " us" << std::endl;


}

std::vector<unsigned int> PmergeMe::recursiveVectorMerge(std::vector<unsigned int> vec)
{
    if (vec.size() <= 1)
        return vec;
    std::vector<unsigned int> left;     
    std::vector<unsigned int> right;     
    int vecMid = vec.size() / 2;
    left = std::vector<unsigned int>(vec.begin(),vec.begin() + vecMid);
    right = std::vector<unsigned int>(vec.begin() + vecMid ,vec.end());
    left = recursiveVectorMerge(left);
    right = recursiveVectorMerge(right);
    return vecMerge(left, right);
}

std::vector<unsigned int> PmergeMe::vecMerge(std::vector<unsigned int> left, std::vector<unsigned int> right)
{
    std::vector<unsigned int> result;
    while (!left.empty() && !right.empty())
    {
        if (left.front() <= right.front())
        {
            result.push_back(left.front());
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    while (!left.empty())
    {
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (!right.empty())
    {
        result.push_back(right.front());
        right.erase(right.begin());
    }
    //std::cout << "result = ";
    //printVector(result);
    //std::cout << std::endl;
    return result;
}

void PmergeMe::sortList(std::list<unsigned int> list)
{
    std::cout << std::endl;

    std::clock_t start = std::clock();
    list = recursiveListMerge(list);
    double time_taken = GET_DURATION(start);

    std::cout << "Time to process a range of " << list.size() <<" elements with std::list : " << time_taken << " us" << std::endl;
}

std::list<unsigned int> PmergeMe::recursiveListMerge(std::list<unsigned int> list)
{
    if (list.size() <= 1)
        return list;
    std::list<unsigned int> left;     
    std::list<unsigned int> right;     
    int listMid = list.size() / 2;
    for (int i = 0; i < listMid; i++)
    {
        left.push_back(list.front());
        list.pop_front();
    }
    right = list;
    left = recursiveListMerge(left);
    right = recursiveListMerge(right);
    return listMerge(left, right);
}

std::list<unsigned int> PmergeMe::listMerge(std::list<unsigned int> left, std::list<unsigned int> right)
{
    std::list<unsigned int> result;
    while (!left.empty() && !right.empty())
    {
        if (left.front() <= right.front())
        {
            result.push_back(left.front());
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    while (!left.empty())
    {
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (!right.empty())
    {
        result.push_back(right.front());
        right.erase(right.begin());
    }
    //std::cout << "result = ";
    //printlist(result);
    //std::cout << std::endl;
    return result;
}