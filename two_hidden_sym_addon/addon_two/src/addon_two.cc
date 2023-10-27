#include <functional>
#include <string>
#include <iostream>
#include "Binding.hpp"
#include "derived_class.h"

// module declaration begin

//UsingCppType(BaseClass);
// if CMAKE_CXX_VISIBILITY_PRESET set to hidden 
UsingOtherModuleCppType(addon_one, BaseClass);
UsingCppType(DerivedClass);

static void Init() {
    std::cout << "Init addon 2" << std::endl;
    puerts::DefineClass<DerivedClass>()
        .Extends<BaseClass>()
        .Constructor()
        .Method("bar", MakeFunction(&DerivedClass::bar))
        .Register();
}

PESAPI_MODULE(addon_two, Init)

// module declaration end
