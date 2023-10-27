#include <functional>
#include <string>
#include <iostream>
#include "Binding.hpp"

class HelloWorld
{
public:
    HelloWorld(int p) {
        Field = p;
    }

    void Foo(std::function<bool(int, int)> cmp) {
        bool ret = cmp(Field, StaticField);
        std::cout << "Foo, Field: " << Field << ", StaticField: " << StaticField << ", compare result:" << ret << std::endl;
    }
    
    static int Bar(std::string str) {
        std::cout << "Bar, str:" << str << std::endl;
        return  StaticField + 1;
    }
    
    int Field;
    
    static int StaticField;
};

int HelloWorld::StaticField = 0;

// module declaration begin

UsingCppType(HelloWorld);

static void Init() {
    puerts::DefineClass<HelloWorld>()
        .Constructor<int>()
        .Method("Foo", MakeFunction(&HelloWorld::Foo))
        .Function("Bar", MakeFunction(&HelloWorld::Bar))
        .Property("Field", MakeProperty(&HelloWorld::Field))
        .Variable("StaticField", MakeVariable(&HelloWorld::StaticField))
        .Register();
}

PESAPI_MODULE(hello_world, Init)

// module declaration end
