#include "BitcoinExchange.hpp"

int validateLine(std::string str)
{
    std::string time = str.substr(0, str.find(" | "));
    std::string val = str.substr(str.find(" | ") + strlen(" | "), str.size());
    if (time == "date" && val == "value")
        return 0;
    for (size_t i = 0; i < val.size(); i++)
    {
        if (val[i] != '.' && !std::isdigit(val[i]))
        {
            std::cout << val << " is an invalid value." << std::endl;
            return 0;
        }
    }
    
    std::istringstream iss(val);
    float f;
    iss >> std::setprecision(10) >> f;
    std::string year = time.substr(0, time.find("-"));
    time = time.substr(time.find("-") + 1, time.size());
    std::string month = time.substr(0, time.find("-"));
    std::string day = time.substr(time.find("-") + 1, time.size());
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
    if (f > 1000)
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
    getline(file, tmp);
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
    std::istringstream iss(val);
    if (!(iss >> std::setprecision(10) >> result.second))
        result.second = 0;
    result.first = time;
    return result;
}

void getBtcValue(std::string str, std::map<std::string, float> map)
{
    std::string time = str.substr(0, str.find(" | "));
    std::string val = str.substr(str.find(" | ") + strlen(" | "), str.size());
    float f = std::atof(val.c_str());
    for (std::map<std::string, float>::iterator it = map.begin(); it != map.end(); it++)
    {
        if ((*it).first > time)
        {
            if (it == map.begin())
                return;
            it--;
            std::cout << time << " => " << val << " = " << f * (*it).second << std::setprecision(15) << std::endl;
            return;
        }
    }
}