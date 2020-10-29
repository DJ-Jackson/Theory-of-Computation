//
// Created by djjac on 9/10/2020.
//

#ifndef PROJECT_A_FILE_H
#define PROJECT_A_FILE_H

#include <iostream>
#include <vector>


class File
{
private:
    std::vector<std::string> all_lines;
    std::vector<std::string> all_results;
    std::string readname, writename;
    int largest{}, file_len = 0;

public:
    explicit File(const std::string& filename);

    void readFile();
    void evaluateFile();
    void largestStr();
    void writeFile();
};

#endif //PROJECT_A_FILE_H
