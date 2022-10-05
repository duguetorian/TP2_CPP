#include <iostream>
#include <functional>

#include "OperatorPlus.h"
#include "Operator.h"


int OperatorPlus::operator()(int left, int right) const
{
    return left + right;
}

void OperatorPlus::print(std::ostream& os, int left, int right) const
    {
        os << left  << " + " <<  right << " = " << operator()(left, right) << "\n";
    
    }