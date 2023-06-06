#include <iostream>
#include <fstream>
#include <sstream>
#include "FileReplace.hpp"
int main(int ac, char **av)
{
    if (ac == 4)
    {
        FileReplace file(av[1]);
        if(file.getFileStream()->fail())
        {
            std::cout << "Error: cannot open file." << std::endl;
            return 1;
        }
        file.stringReplace(av[1], av[2], av[3]);
    }
    return 0;
}
