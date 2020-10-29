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

std::string Literal::isLiteral(const string& number)
{
    bool exponent_state{false}, decimal_state{false}, start{true}, number_state{false};
    for (auto digit: number)
    {
        if (digit == '.')
        {
            if (exponent_state || decimal_state || !number_state)
            {
                return "is NOT a valid numeric literal";
            }
            decimal_state = true;
        }
        else if (Literal::isExp(digit))
        {
            if (start || exponent_state || !number_state)
            {
                return "is NOT a valid numeric literal";
            }
            decimal_state = false;
            exponent_state = true;
            number_state = false;
        }
        else if (Literal::isSign(digit))
        {
            if (decimal_state || number_state || (!start & !exponent_state))
            {
                return "is NOT a valid numeric literal";
            }
        }
        else if (!Literal::isNum(digit))
        {
            return "is NOT a valid numeric literal";
        }
        else
        {
            if (!number_state)
            {
                number_state = true;
            }
        }
        if (start)
        {
            start = false;
        }
    }
    if ((exponent_state & !number_state) || !number_state)
    {
        return "is NOT a valid numeric literal";
    }
    return "is a valid numeric literal";
}
