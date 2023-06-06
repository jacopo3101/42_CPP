#pragma once
#ifndef FILEREPLACE_HPP
#define FILEREPLACE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
class FileReplace
{
private:
    std::ifstream *fileStream;
public:
    FileReplace(char *filePath);
    ~FileReplace();
    void stringReplace(char *filePath, char *s1, char *s2);
    std::ifstream *getFileStream();
};
#endif
