#include "Serializer.hpp"

int main()
{
    Data *ptr1 = new Data;
    ptr1->array[5] = 5;
    ptr1->DataName = "DataName";
    uintptr_t n = Serializer::serialize(ptr1);
    Data *ptr2 = Serializer::deserialize(n);
    std::cout << ptr2->DataName << " " << ptr2->array[5] << std::endl;
    if (ptr1 == ptr2)
        std::cout << "ptr1 and ptr2 points to the same data struntures" << std::endl;
    else
        std::cout << "ptr1 and ptr2 points to different data strucrures" << std::endl;
    delete ptr1;
    return 0;
}
