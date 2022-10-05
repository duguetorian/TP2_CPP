#include <iostream>
#include <functional>

#include "OperatorTimes.h"
#include "Operator.h"

int OperatorTimes::operator()(int left, int right) const
    {
        return left * right;
    }

void OperatorTimes::print(std::ostream& os, int left, int right) const
    {
        os << left  << " x " <<  right << " = " << operator()(left, right) << "\n";
    }
