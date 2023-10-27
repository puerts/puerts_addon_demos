#pragma once

#include "base_class.h"

class PESAPI_MODULE_EXPORT DerivedClass : public BaseClass {
public:
    DerivedClass();
    virtual ~DerivedClass();

    void print() override;
    
    void bar();
};