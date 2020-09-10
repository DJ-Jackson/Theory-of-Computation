//
// Created by djjac on 9/10/2020.
//

#define ASCII_ZERO 48

#include <iostream>
#include "numliteral.h"
using namespace std;


bool Literal::isNum(char c)
{
    int digit = 0;
    digit *= 10;
    digit += c - ASCII_ZERO;
    if (digit < 0 || digit > 9)
    {
        return false;
    }
    return true;
}

bool Literal::isSign(char c)
{
    int sign = c;
    if (sign == 43 || sign == 45)
    {
        return true;
    }
    return false;
}

bool Literal::isExp(char c)
{
    if (c == 'e' || c == 'E')
    {
        return true;
    }
    return false;
}

bool Literal::isLiteral(string number)
{
    bool exponent_state = false, decimal_state = false, start = true;
    for (auto digit: number)
    {
        if (digit == '.')
        {
            if (exponent_state)
            {
                return false;
            }
            decimal_state = true;
        }
        else if (Literal::isExp(digit))
        {
            if (start)
            {
                return false;
            }
            decimal_state = false;
            exponent_state = true;
        }
        else if (Literal::isSign(digit))
        {
            if (decimal_state)
            {
                return false;
            }
        }
        else if (!Literal::isNum(digit))
        {
            return false;
        }
        if (start)
        {
            start = false;
        }
    }
    return true;
}
