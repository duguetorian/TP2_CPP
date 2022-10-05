#include <iostream>
#include <functional>

#include "OperatorPlus.h"
#include "Operator.h"


int OperatorPlus::operator()(int left, int right) const
{
    return left + right;
}
