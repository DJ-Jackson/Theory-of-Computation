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

void File::addLine(std::string line, output_ptr &curr)
{
    auto temp = new Output;
    temp->number = line;
    temp->next = nullptr;
    curr = temp;
}

void File::readFile()
{
    string temp{};
    auto curr = new Output;
    curr->next = new Output;
    curr->result = "";
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
            File::addLine(temp, curr);
            if (!curr_head)
            {
                curr_head = curr;
            }
            cout << "Curr: " << curr << endl;
            cout << TAB << "Test: " << curr->number << endl;
            cout << TAB << "Result: " << curr->result << endl;
            cout << TAB << "Next: " << curr->next << endl;
            curr = curr->next;
            file_len++;
        }
        curr = nullptr;
        all_lines = curr_head;
        literal_file.close();
        cout << "Closed\n";
    }
}

void File::evaluateFile()
{
    output_ptr curr = all_lines;
    while (curr)
    {
        curr->result = isLiteral(curr->number);
        cout << "Curr: " << curr << endl;
        cout << TAB << "Test: " << curr->number << endl;
        cout << TAB << "Result: " << curr->result << endl;
        cout << TAB << "Next: " << curr->next << endl;
        curr = curr->next;
    }
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
        cout << "Writing to file " << filename << "..." << endl;
        while (curr)
        {
            cout << "Curr >> " << curr->number << endl;
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
        cout << "Finished writing to file.\n\n";
    }
}
