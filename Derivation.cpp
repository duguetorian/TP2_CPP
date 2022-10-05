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


