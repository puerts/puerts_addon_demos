#include <functional>
#include <string>
#include <iostream>
#include "Binding.hpp"
#include "base_class.h"

// module declaration begin

UsingCppType(BaseClass);

static void Init() {
    std::cout << "Init addon 1" << std::endl;
    puerts::DefineClass<BaseClass>()
        .Constructor()
        .Method("print", MakeFunction(&BaseClass::print))
        .Method("foo", MakeFunction(&BaseClass::foo))
        .Register();
}

PESAPI_MODULE(addon_one, Init)

// module declaration end
