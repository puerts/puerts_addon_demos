local puerts = require "puerts"

local puerts_test_addon = puerts.load("../addon_test/puerts_test_addon")

local TestClass = puerts_test_addon.TestClass

--static function
TestClass.Overload();
TestClass.Overload(1);
TestClass.Overload(1, 2);
TestClass.Overload("hello", 2);

local succ, msg = pcall(TestClass.Overload, "hello");

if not succ then
     print("caught function overload error:", msg);
end

local obj = TestClass();
obj = TestClass(8, 9);

--method
obj:OverloadMethod()
obj:OverloadMethod(1024)
obj:OverloadMethod(4294967295)

local succ, msg = pcall(obj.OverloadMethod, obj, "hello");

if not succ then
     print("caught method overload error:", msg);
end

--property
print(obj.X, obj.Y)
obj.X = 96
obj.Y = 97
print(obj.X, obj.Y)
obj:OverloadMethod()

--base method
obj:Foo(888);

--pass object
TestClass.PrintInfo(obj:GetSelf())

--static variable
print(TestClass.StaticInt)
TestClass.StaticInt = 789
print(TestClass.StaticInt)
TestClass.PrintInfo(obj:GetSelf())

function ref(v)
    return {v}
end

function unref(b)
    return b[1]
end

--ref & pointer
local r = ref(999);
local ret = obj:Ref(r);
print("$unref:" .. unref(r) .. ", ret:" .. ret);
obj:ConstRef(999);

r = ref(888);
ret = obj:Ptr(r);
print("$unref:" .. unref(r) .. ", ret:" .. ret);

local sr = ref("ts msg for ref");
obj:StrRef(sr);
print("$unref<string>:" .. unref(sr));

print(obj:CStr("ts str"));

sr = ref("ts msg for ptr");
obj:StrPtr(sr);
print("$unref<string>:" .. unref(sr))

local AdvanceTestClass = puerts_test_addon.AdvanceTestClass;
local obj2  = AdvanceTestClass(100);

obj2:StdFunctionTest(function (x, y) 
    print('x=' .. x .. ",y=" .. y);
    return x + y;
end)

local succ, msg = pcall(AdvanceTestClass, 1, 2, 3);

if not succ then
     print("caught constructor overload error:", msg);
end
