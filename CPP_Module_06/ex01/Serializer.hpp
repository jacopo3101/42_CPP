#include <stdint.h>
#include <iostream>

struct Data
{
    std::string DataName;
    int array[10];
};


class Serializer
{
private:
    Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    ~Serializer();
};