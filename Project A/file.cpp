//
// Created by djjac on 9/10/2020.
//

#include "file.h"
#include <iostream>
#include <fstream>
using namespace std;

File::File(std::string filename)
{
    this->filename = filename;
}

void File::length()
{
    ifstream literal_file;
    literal_file.open(filename);
    if (literal_file.is_open())
    {
        while (!literal_file.eof())
        {
            file_len++;
        }
        literal_file.close();
    }
}

void File::readFile()
{
    lines = new std::string[file_len];
    ifstream literal_file;
    literal_file.open(filename);
    if (literal_file)
    {
        for (auto line: *lines)
        {
            getline(literal_file, line);
        }
        literal_file.close();
    }
}

void File::writeFile() {

}
