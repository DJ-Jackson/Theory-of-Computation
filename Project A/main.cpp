#include "numliteral.h"
#include <iostream>
using namespace std;
using namespace literal;

int main()
{
    string number[] = {"+1.0", "e5", "0", "a-3.5E6"};
    for (auto num: number)
    {
        cout << "Test: " << num << endl;
        cout << "Result: " << isLiteral(num) << endl << endl;
    }
}
