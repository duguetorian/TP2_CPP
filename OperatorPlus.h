#ifndef OPERATOR_PLUS_H
#define OPERATOR_PLUS_H

#include <iostream>
#include <functional>

#include "Operator.h"


class OperatorPlus: public Operator
{
public:
    int operator()(int left, int right) const;
    void print(std::ostream& os, int left, int right) const;
};


#endif //OPERATOR_PLUS_H
