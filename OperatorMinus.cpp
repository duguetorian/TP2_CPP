#include <iostream>
#include <functional>

#include "OperatorMinus.h"
#include "Operator.h"


const bool OperatorMinus::isPositive(int left, int right) const
{
    if (left >= right)
    {
        return true;
    }
    return false;
}

int OperatorMinus::operator()(int left, int right) const
{
    if (isPositive(left, right))
    {
        return left - right;
    }
    return 0;
}

void OperatorMinus::print(std::ostream& os, int left, int right) const
{
    if (isPositive(left, right))
    {
        os << left << " - " << right << " = " << operator()(left, right) << "\n";
        return;
    }
    os << "The substraction didn't return a positive integer\n";
}
