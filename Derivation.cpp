#include "Operation.h"
#include "Derivation.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <tuple>

#include "DerivationIterator.h"


Derivation::Derivation(std::vector<int> numbers, int target):
    availables{numbers}, target{target}, used_operations{}
{}

int Derivation::closest() const
{
    int selected_number = availables.at(0);
    int min_distance = abs(target - selected_number);
    for(int i : availables)
    {
        if (abs(target - i) < min_distance)
        {
            selected_number = i;
            min_distance = abs(target - i);
        }
    }
    return selected_number;
}

int Derivation::distance() const
{
    return abs(target - closest());
}

bool Derivation::addOperation(int left, const Operator& o, int right)
{
    bool left_found = false;
    bool right_found = false;
    for (int i : availables)
    {
        if (i == left && !left_found)
        {
            left_found = true;
        }
        else if (availables.at(i) == right)
        {
            right_found = true;
        }
    }
    if (!left_found || !right_found)
    {
        return false;
    }
    else if (o(left, right) == 0)
    {
        return false;
    }
    Operation operation(left, o, right);
    used_operations.push_back(&operation);
    availables.erase(std::find(availables.begin(), availables.end(), left));
    availables.erase(std::find(availables.begin(), availables.end(), right));
    availables.push_back(o(left, right));
    return true;
}

DerivationIterator Derivation::begin()
{
    DerivationIterator DerivIterator(*this);
    return DerivIterator;
}

DerivationIterator Derivation::end()
{
    DerivationIterator DerivIterator;
    return DerivIterator;
}
