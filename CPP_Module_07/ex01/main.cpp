#include <iostream>
#include "iter.hpp"
template<typename T>
void print(T t)
{
    std::cout << t << std::endl;
}

int main(void)
{
    int arr[5] = {1,2,3,4,5};
    std::string strArr[5] = {"mario", "ciro", "cane", "srgtrgf","lokoioi"};
    iter(arr, 5, &print<int>);
    iter(strArr, 5, &print<std::string>);
    return 0;
}
