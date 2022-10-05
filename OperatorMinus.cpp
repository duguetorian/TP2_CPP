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
