#ifndef OPERATOR_TIMES_H
#define OPERATOR_TIMES_H

#include <iostream>
#include <functional>

#include "Operator.h"


class OperatorTimes: public Operator
{
public:
    int operator()(int left, int right) const;
    virtual void print(std::ostream& os, int left, int right) const = 0;
};


#endif //OPERATOR_TIMES_H