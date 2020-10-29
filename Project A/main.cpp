#include "file.h"
using namespace std;


int main()
{
    string test_cases[] = {"tests/ng_test.txt"};
    for (const auto& cases: test_cases)
    {
        File test(cases);
        test.readFile();
        test.evaluateFile();
        test.largestStr();
        test.writeFile();
    }

}
