#include "BitcoinExchange.hpp"

int main(int argc, char const **argv)
{
    if (argc == 2)
    {
        std::map<std::string, float> m = fillMap("data.csv", ",");
        std::fstream file;
        std::string tmp;
        file.open(argv[1], std::ios::in);
        if (file.is_open())
        {
            while(getline(file, tmp))
            {
                if (!validateLine(tmp))
                    continue;
                getBtcValue(tmp, m);
            }
        }
    }
    return 0;
}
