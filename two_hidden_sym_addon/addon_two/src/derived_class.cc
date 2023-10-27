#include "derived_class.h"
#include <iostream>

DerivedClass::DerivedClass() {}

DerivedClass::~DerivedClass() {}

void DerivedClass::print() {
    std::cout << "DerivedClass print" << std::endl;
}

void DerivedClass::bar() {
    std::cout << "DerivedClass bar" << std::endl;
}
