#include "file.h"
using namespace std;


int main()
{
    string test_cases[] = {"tests/1.txt", "tests/2.txt", "tests/3.txt", "tests/4.txt"};
    for (const auto& cases: test_cases)
    {
        File test(cases);
        test.readFile();
        test.evaluateFile();
        test.writeFile();
    }

}
