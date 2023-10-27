#pragma once

#include "pesapi.h"

class PESAPI_MODULE_EXPORT BaseClass {
public:
    BaseClass();
    virtual ~BaseClass();

    virtual void print();
    
    void foo();
};
