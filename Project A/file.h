//
// Created by djjac on 9/10/2020.
//

#ifndef PROJECT_A_FILE_H
#define PROJECT_A_FILE_H

#include <iostream>

class File
{
private:
    std::string *lines;
    std::string filename;
    int file_len = 0;

public:
    File(std::string filename);
    void length();
    void readFile();
    void writeFile();
};

#endif //PROJECT_A_FILE_H
