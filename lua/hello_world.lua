local puerts = require "puerts"

local hello_world = puerts.load('../hello_world/hello_world')
local HelloWorld = hello_world.HelloWorld

local obj = HelloWorld(101)
obj:Foo(function(x, y) 
    return x > y
end)

HelloWorld.Bar("hello")

HelloWorld.StaticField = 999
obj.Field = 888
obj:Foo(function(x, y) 
    return x > y
end)
