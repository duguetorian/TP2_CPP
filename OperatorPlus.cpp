#include <iostream>
#include <functional>

#include "OperatorPlus.h"
#include "Operator.h"


int OperatorPlus::operator()(int left, int right) const
{
    return left + right;
}

int void print(std::ostream& os, int left, int right) const=0;
    {
        os << left  << " + " <<  right << "=" << operator()() << "\n";
    
    }