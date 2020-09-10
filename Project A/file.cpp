//
// Created by djjac on 9/10/2020.
//

#include "file.h"
#include "numliteral.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace Literal;


File::File(std::string filename)
{
    this->filename = filename;
}

void File::readFile()
{
    string temp{};
    fstream literal_file;
    cout << "Opening " << filename << "...\n";
    literal_file.open(filename);
    if (literal_file)
    {
        while (getline(literal_file, temp))
        {
            lines += temp + " ";
            file_len++;
        }
        literal_file.close();
        cout << "Closed\n";
    }
}

void File::evaluateFile()
{
    File::readFile();
    string curr[file_len];
    int curr_pos{}, pos{};
    while (!lines.empty())
    {
        if (lines[pos] == ' ')
        {
            curr[curr_pos] = lines.substr(0, pos);
            lines.erase(0, pos + 1);
            curr_pos++;
            pos = 0;
        }
        else
        {
            pos++;
        }
    }
    for (auto line: curr)
    {
        cout << "Test: " << line << endl;
        cout << "Result: " << isLiteral(line) << endl;
    }

}

void File::writeFile() {

}
