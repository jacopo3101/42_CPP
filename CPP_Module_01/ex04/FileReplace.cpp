#include "FileReplace.hpp"

FileReplace::FileReplace(char *filePath)
{
    fileStream = new std::ifstream(filePath, std::ios::in | std::ios::out);
}

std::ifstream *FileReplace::getFileStream()
{
    return fileStream;
}

FileReplace::~FileReplace()
{
    fileStream->close();
    delete fileStream;
}

void FileReplace::stringReplace(char *filePath, char *s1, char *s2)
{
    std::stringstream buffer;
    std::string newString;
    std::string strPath(filePath);
    buffer << fileStream->rdbuf();
    std::string str = buffer.str();
    size_t index = str.find(s1, 0);
    size_t oldIndex = 0;
    while (index != std::string::npos)
    {
        newString.append(str.begin() + oldIndex, str.begin() + index);
        newString.append(s2);
        oldIndex = index + strlen(s1);
        index = str.find(s1, index + 1);
    }
    newString.append(str.begin() + oldIndex, str.end());
    std::ofstream repalceFile(strPath.append(".replace").c_str());
    if(repalceFile.fail())
    {
        std::cout << "Failed to create replace file." << std::endl;
        return ;
    }
    repalceFile << newString;
    repalceFile.close();
}