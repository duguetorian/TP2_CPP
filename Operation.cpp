#include <iostream>
#include <optional>

#include "Operator.h"
#include "Operation.h"

Operation::Operation(int left, const Operator& n, int right):
    left{left}, op{n}, right{right}
    {}

std::ostream& operator<<(std::ostream& os, Operation& operation)
{
    operation.op.print(operation.left, operation.right);
    return os;
}