#include <fstream>
#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <limits>


std::map<std::string, float> fillMap(std::string path, const char *token);

std::pair<std::string, float> makePair(std::string str, const char *token);

int validateLine(std::string str);

void getBtcValue(std::string str, std::map<std::string, float> map);
