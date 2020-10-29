//
// Created by djjac on 9/10/2020.
//

#define TAB "    "

#include "file.h"
#include "numliteral.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using namespace Literal;


File::File(string filename)
{
    this->readname = filename;
    const char* write_end = "_output.txt";
    writename = filename + write_end;
    cout << "Write File Name " << writename << ".\n";
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
            cout << temp << endl;
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
        cout << "Result for " << number << " -> " << result << endl;
        all_results.push_back(result);
    }
    cout << endl;
}

void File::largestStr()
{
    int temp;
    for (const auto& number: all_lines)
    {
        temp = number.length();
        cout << "The length for " << number << " -> " << temp << endl;
        if (temp > largest)
        {
            largest = temp;
        }
    }
    cout << endl;
    largest += 8;
}

void File::writeFile()
{
    fstream literal_file;
    literal_file.open(writename, fstream::out);
    cout << "yer\n\n";
    if (literal_file)
    {
        int difference, tabs, spaces, size = all_lines.size();
        string line{}, number, result;
        cout << "Writing to file " << writename << "..." << endl;
        for (int i = 0; i < size; i++)
        {
            number = all_lines[i];
            result = all_results[i];
            cout << "Curr >> " << number << endl;
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
        cout << "Finished writing to file.\n\n";
    }
}
