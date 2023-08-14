#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include "Binding.hpp"
#include "vector_to_array.h"

class VectorTest
{
public:
    static std::vector<int> convert(std::vector<int> input) {
        for (int i = 0; i < input.size(); i++) {
            input[i]++;
        }
        return input;
    }
};


// module declaration begin

UsingCppType(VectorTest);

void Init() {
    puerts::DefineClass<VectorTest>()
        .Function("convert", MakeFunction(&VectorTest::convert))
        .Register();
}

PESAPI_MODULE(vector_to_array, Init)

// module declaration end
