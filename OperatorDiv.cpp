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

void OperatorDiv::print(std::ostream& os, int left, int right) const
{
    if (isInteger(left, right))
    {
        os << left << " / " << right << " = " << operator()(left, right) << "\n";
        return;
    }
    os << "The division didn't return an integer\n";
}
