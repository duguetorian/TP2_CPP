#ifndef OPERATOR_MINUS_H
#define OPERATOR_MINUS_H

#include <iostream>
#include <functional>

#include "Operator.h"


class OperatorMinus: public Operator
{
private:
    const bool isPositive(int left, int right) const;

public:
    int operator()(int left, int right) const;
};


#endif //OPERATOR_MINUS_H
