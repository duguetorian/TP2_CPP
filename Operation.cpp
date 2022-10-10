#include <iostream>
#include <optional>

#include "Operator.h"
#include "Operation.h"

Operation::Operation(int left, const Operator& n, int right):
    left{left}, right{right}
    {
        used_operator = &n;
    }

std::ostream& operator<<(std::ostream& os, Operation& operation)
{
    operation.used_operator->print(os, operation.left, operation.right);
    return os;
}