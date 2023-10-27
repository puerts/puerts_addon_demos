#include "base_class.h"
#include <iostream>

BaseClass::BaseClass() {}

BaseClass::~BaseClass() {}

void BaseClass::print() {
    std::cout << "BaseClass print" << std::endl;
}

void BaseClass::foo() {
    std::cout << "BaseClass foo" << std::endl;
}
