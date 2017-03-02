'use strict';


let func = () => {
  for(var i = 0; i < 2; i++) {
    return function() { return i; };
  }

}

console.log(func[0]());

let fibs = () => {
let count = 1;
let sum = 0;
let result = 0;
let term1 = 0;
let term2 = 1;
while(result < 4000000) {

result = term1 + term2;
term1 = term2;
term2 = result;


console.log("sum" + sum, "result" + result);
if (result % 2 === 0 ) {
  sum += result;
}


count++;
}


return sum;
}


fibs();
