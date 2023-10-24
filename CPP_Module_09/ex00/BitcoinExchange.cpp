#include "BitcoinExchange.hpp"

int validateLine(std::string str)
{
    std::string time = str.substr(0, str.find(" | "));
    std::string val = str.substr(str.find(" | ") + strlen(" | "), str.size());
    std::istringstream iss(val);
    float f;
    iss >> std::setprecision(10) >> f;
    if (time == "date" && val == "value")
    {
        std::cout << "date | value\n";
        return 0;
    }
    std::string year = time.substr(0, time.find("-"));
//    time.erase(time.find("-"), time.end());
    time = time.substr(time.find("-") + 1, time.size());
    std::cout << "time = " << time << std::endl;
    std::string month = time.substr(0, time.find("-"));
    std::string day = time.substr(time.find("-") + 1, time.size());
    std::cout << "year = " << year << " month = " << month << " day = " << day << std::endl;
    if (std::atoi(year.c_str()) > 3000 || std::atoi(year.c_str()) < 1800 || std::atoi(month.c_str()) > 12
        || std::atoi(month.c_str()) < 1 || std::atoi(day.c_str()) > 31 || std::atoi(day.c_str()) < 1)
    {
        std::cout << "Error: invalid data\n";
        return 0;
    }
    if (f < 0)
    {
        std::cout << "Error: not a positive number\n";
        return 0;
    }
    if (f > std::numeric_limits<int>::max())
    {
        std::cout << "Error: too large number\n";
        return 0;
    }
    return 1;
}

std::map<std::string, float> fillMap(std::string path, const char *token)
{
    std::fstream file;
    std::string tmp;
    std::map<std::string, float> map;
    file.open(path.c_str(), std::ios::in);
    if (file.is_open())
    {
        while(getline(file, tmp))
            map.insert(makePair(tmp, token));
        file.close();
    }
    return map;
}

std::pair<std::string, float> makePair(std::string str,const char *token)
{
    std::pair<std::string, float> result;
    std::string time = str.substr(0, str.find(token));
    std::string val = str.substr(str.find(token) + strlen(token), str.size());
    //std::cout << "val = " << val << " - time = " << time << " " << val.find_first_not_of(" ") << std::endl;
    std::istringstream iss(val);
    if (iss >> std::setprecision(10) >> result.second) {
        std::cout << result.second << std::setprecision(10) << std::endl;
    } else {
        std::cerr << "Conversion failed" << std::endl;
    }
    result.first = time;
    return result;
}