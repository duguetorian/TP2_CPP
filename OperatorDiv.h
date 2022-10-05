#ifndef OPERATOR_DIV_H
#define OPERATOR_DIV_H

#include <iostream>
#include <functional>

#include "Operator.h"


class OperatorDiv: public Operator
{
private:
    const bool isInteger(int left, int right) const;

public:
    override int operator()(int left, int right) const;
};


#endif //OPERATOR_DIV_H
