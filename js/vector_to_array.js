const puerts = require("puerts");

let vector_to_array = puerts.load('../vector_to_array/vector_to_array');

const VectorTest = vector_to_array.VectorTest

const input = [0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5 ];
const output = VectorTest.convert(input);

console.log(output);
