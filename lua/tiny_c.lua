local puerts = require "puerts"

local tiny_c = puerts.load("../tiny_c/tiny_c")

local Calc = tiny_c.Calc

print(Calc.Add(1, 2))
