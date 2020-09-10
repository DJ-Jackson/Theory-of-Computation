//
// Created by djjac on 9/10/2020.
//

#ifndef PROJECT_A_FILE_H
#define PROJECT_A_FILE_H

#include <iostream>


class File
{
private:
    struct Output
    {
        std::string number;
        std::string result;
        int size;
        Output* next;
    };

    typedef Output* output_ptr;
    output_ptr all_lines;

    std::string filename;
    int file_len = 0;

public:
    explicit File(std::string filename);
    void readFile();
    void evaluateFile();
    int largestStr();
    void writeFile();
};

#endif //PROJECT_A_FILE_H
