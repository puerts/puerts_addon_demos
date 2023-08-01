const puerts = require("puerts");

let hello_world = puerts.load('../hello_world/hello_world');
const HelloWorld = hello_world.HelloWorld;

const obj = new HelloWorld(101);
obj.Foo((x, y) => x > y);

HelloWorld.Bar("hello");

HelloWorld.StaticField = 999;
obj.Field = 888;
obj.Foo((x, y) => x > y);
