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

}

void File::writeFile() {

}
