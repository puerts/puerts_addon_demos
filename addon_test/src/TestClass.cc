#include "TestClass.h"

void BaseClass::Foo(int p)
{
	printf("BaseClass::Foo(%d)\n", p);
}

TestClass::TestClass()
{
	printf("0 TestClass::TestClass()\n");
	X = 0;
	Y = 0;
}

TestClass::TestClass(int32_t InX, int32_t InY)
{
	printf("1 TestClass::TestClass(%d, %d)\n", InX, InY);
	X = InX;
	Y = InY;
}

int32_t TestClass::Add(int32_t a, int32_t b)
{
	return a + b;
}

void TestClass::Overload()
{
	printf("0 TestClass::Overload()\n");
}

void TestClass::Overload(int32_t a)
{
	printf("1 TestClass::Overload(%d)\n", a);
}

void TestClass::Overload(int32_t a, int32_t b)
{
	printf("2 TestClass::Overload(%d, %d)\n", a, b);
}

void TestClass::Overload(std::string a, int32_t b)
{
	printf("3 TestClass::Overload(%s, %d)\n", a.c_str(), b);
}


int32_t TestClass::OverloadMethod()
{
	printf("0 TestClass::OverloadMethod(), X = %d, Y = %d\n", X, Y);
	return 0;
}

int32_t TestClass::OverloadMethod(int32_t a)
{
	printf("1 TestClass::OverloadMethod(%d), X = %d, Y = %d\n", a, X, Y);
	return 1;
}

uint32_t TestClass::OverloadMethod(uint32_t a)
{
	printf("2 TestClass::OverloadMethod(%u), X = %d, Y = %d\n", a, X, Y);
	return a;
}

int64_t TestClass::OverloadMethod(int64_t a)
{
	printf("3 TestClass::OverloadMethod(%lld), X = %d, Y = %d\n", a, X, Y);
	return a;
}

TestClass * TestClass::GetSelf()
{
	printf("1 TestClass::GetSelf()\n");
	return this;
}

void TestClass::PrintInfo(TestClass * tc)
{
	printf("0 TestClass::PrintInfo(), X = %d, Y = %d, StaticInt=%d\n", tc->X, tc->Y, StaticInt);
}


int TestClass::Ref(int32_t & a)
{
	printf("TestClass::Ref(%d)\n", a);
	++a;
	return a + 1;
}

void TestClass::StrRef(std::string & str)
{
    printf("TestClass::StrRef(%s)\n", str.c_str());
    str += " append by c++";
}

int TestClass::Ptr(int32_t * a)
{
    printf("TestClass::Ptr(%d), %p\n", *a, a);
    ++(*a);
    return *a + 1;
}

const char* TestClass::CStr(const char* str)
{
    printf("TestClass::CStr(%s)\n", str);
    return "hehe..";
}

void TestClass::StrPtr(std::string * str)
{
    printf("TestClass::StrPtr(%s) %p\n", (*str).c_str(), str);
    *str += " append by c++";
}

void TestClass::ConstRef(const int32_t & a)
{
	printf("TestClass::ConstRef(%d)\n", a);
}

int TestClass::StaticInt = 0;

const float TestClass::Ten = 10;