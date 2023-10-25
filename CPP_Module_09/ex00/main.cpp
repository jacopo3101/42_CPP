#include "BitcoinExchange.hpp"

int main(int argc, char const **argv)
{
    if (argc == 2)
    {
        std::map<std::string, float> m = fillMap("data.csv", ",");
        // for (std::map<std::string, float>::iterator it = m.begin(); it != m.end(); it++)
        // {
        //     std::cout << (*it).first << "," << (*it).second << std::setprecision(10) << std::endl;
        // }
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
