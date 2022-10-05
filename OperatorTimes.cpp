#include <iostream>
#include <functional>

#include "OperatorTimes.h"
#include "Operator.h"

int OperatorTimes::operator()(int left, int right) const
    {
        return left * right;
    }