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


File::File(std::string filename)
{
    this->filename = filename;
    all_lines = nullptr;
}

void File::readFile()
{
    string temp{};
    auto curr = new Output;
    curr->next = new Output;
    curr->result = false;
    curr->number = "";
    auto curr_head = new Output;
    curr_head = nullptr;
    fstream literal_file;
    cout << "Opening " << filename << "...\n";
    literal_file.open(filename);
    if (literal_file)
    {
        while (getline(literal_file, temp))
        {
            curr->number = temp;
            if (!curr_head)
            {
                curr_head = curr;
            }
            curr = curr->next;
            curr->next = new Output;
            file_len++;
        }
        all_lines = curr_head;
        literal_file.close();
        cout << "Closed\n";
    }
}

void File::evaluateFile()
{
    File::readFile();
    output_ptr curr = all_lines;
    while (curr->next->next)
    {
        curr->result = isLiteral(curr->number);
        cout << "Test: " << curr->number << endl;
        cout << "Result: " << curr->result << endl;
        curr = curr->next;
    }
    curr->next = nullptr;
}

int File::largestStr()
{
    output_ptr curr = all_lines;
    int largest{}, temp;
    while (curr)
    {
        temp = curr->number.length();
        if (temp > largest)
        {
            largest = temp;
        }
        curr->size = temp;
        curr = curr->next;
    }
    return largest;
}

void File::writeFile()
{
    fstream literal_file(filename);
    if (literal_file)
    {
        output_ptr curr = all_lines;
        int difference, tabs, spaces;
        string line{};
        auto largest = File::largestStr() + 8;
        while (curr)
        {
            difference = largest - curr->size;
            tabs = difference / 4;
            spaces = difference % 4;
            line = curr->number;
            for (int i = 0; i < tabs; i++)
            {
                line += TAB;
            }
            for (int i = 0; i < spaces; i ++)
            {
                line += " ";
            }
            line += curr->result + "\n";
            cout << line;
            literal_file << line;
            curr = curr->next;
        }
        literal_file.close();
    }
}
