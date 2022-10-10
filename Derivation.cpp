#include <iostream>
#include <vector>
#include <iterator>
#include <tuple>


#include "Operation.h"
#include "Derivation.h"
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
        else if (i == right)
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
    // Operation newOperation(left, o, right);
    // used_operations.push_back(newOperation);
    availables.push_back(o(left, right));
    availables.erase(std::find(availables.begin(), availables.end(), left));
    availables.erase(std::find(availables.begin(), availables.end(), right));
    used_operations.emplace_back(left, o, right);
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

std::ostream& operator<<(std::ostream& os, Derivation& deriv)
{
    os << "Target: " << deriv.target << "\n";
    os << "Operations :\n";
    // for (int i=0; i<deriv.used_operations.size(); ++i)
    // {
    //     os << *deriv.used_operations.at(i) << "\n";
    // }
    for (auto i : deriv.used_operations)
    {
        os << *i << "\n";
    }
    os << "Result: " << deriv.closest() << "\n";
    os << "Distance: " << deriv.distance() << "\n";
    return os;
}
