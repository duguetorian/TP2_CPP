#include <iostream>
#include <functional>

#include "OperatorTimes.h"
#include "Operator.h"

int OperatorTimes::operator()(int left, int right) const
    {
        return left * right;
    }

int void print(std::ostream& os, int left, int right) const=0;
    {
        os << left  << " x " <<  right << "=" << operator()() << "\n";
    
    }