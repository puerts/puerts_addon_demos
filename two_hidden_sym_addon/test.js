const puerts = require("puerts");

console.log('loading addon_one');
let addon_one = puerts.load('addon_one/addon_one');
const BaseClass = addon_one.BaseClass;

const obj1 = new BaseClass();
//obj1.print();
obj1.foo();

console.log('loading addon_two');
let addon_two = puerts.load('addon_two/addon_two');
const DerivedClass = addon_two.DerivedClass;

const obj2 = new DerivedClass();
//obj2.print();
obj2.bar();

obj2.foo();