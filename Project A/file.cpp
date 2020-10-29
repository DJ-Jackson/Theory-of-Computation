//
// Created by djjac on 9/10/2020.
//

#define TAB "    "

#include "file.h"
#include "numliteral.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace Literal;


File::File(const string& filename)
{
    this->readname = filename;
    const char* write_end = "_output.txt";
    writename = filename + write_end;
}

void File::readFile()
{
    string temp{};
    fstream literal_file;
    cout << "Opening " << readname << "...\n";
    literal_file.open(readname);
    if (literal_file)
    {
        while (getline(literal_file, temp))
        {
            all_lines.push_back(temp);
            file_len++;
        }
        literal_file.close();
        cout << "Closed\n";
    }
}

void File::evaluateFile()
{
    string result;
    for (const auto& number: all_lines)
    {
        result = isLiteral(number);
        all_results.push_back(result);
    }
}

void File::largestStr()
{
    int temp;
    for (const auto& number: all_lines)
    {
        temp = number.length();
        if (temp > largest)
        {
            largest = temp;
        }
    }
    largest += 8;
}

void File::writeFile()
{
    fstream literal_file;
    literal_file.open(writename, fstream::out);
    if (literal_file)
    {
        int difference, tabs, spaces, size = all_lines.size();
        string line{}, number, result;
        cout << "Writing to file " << writename << "..." << endl << endl;
        for (int i = 0; i < size; i++)
        {
            number = all_lines[i];
            result = all_results[i];
            difference = largest - number.size();
            tabs = difference / 4;
            spaces = difference % 4;
            line = number;
            for (int j = 0; j < tabs; j++)
            {
                line += TAB;
            }
            for (int j = 0; j < spaces; j ++)
            {
                line += " ";
            }
            line += result + "\n";
            cout << line;
            literal_file << line;
        }
        literal_file.close();
        cout << "\nFinished writing to file.\n\n";
    }
}
