const puerts = require("puerts");

let tiny_c = puerts.load('../tiny_c/tiny_c');
const Calc = tiny_c.Calc;

console.log(Calc.Add(1, 2));