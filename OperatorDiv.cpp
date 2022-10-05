#include <iostream>
#include <functional>

#include "OperatorDiv.h"
#include "Operator.h"


const bool OperatorDiv::isInteger(int left, int right) const
{
    if (left % right == 0)
    {
        return true;
    }
    return false;
}

int OperatorDiv::operator()(int left, int right) const
{
    if (isInteger(left, right))
    {
        return left / right;
    }
    return 0;
}
