#ifndef OPERATOR_TIMES_H
#define OPERATOR_TIMES_H

#include <iostream>
#include <functional>

#include "Operator.h"


class OperatorTimes: public Operator
{
public:
    int operator()(int left, int right) const;
};


#endif //OPERATOR_TIMES_H