// Non-optimized solution.
// const isPrime = (num) => {
//   if(num < 2 && num > 0) return true;
//   let start = 2;
//   while(num > start) {
//     if( num % start == 0) return false;
//     else start++;
//   }
//   return true;
// }

// Optimized Solution.
// Not incrementing and checking even numbers.
// Only checking squares.
const isPrime = (num) => {
  if(num <= 2 && num > 0) return true;
  if(num % 2 === 0) return false;
  let i = 3;

  while(Math.sqrt(num) > i) {
    if(num % i === 0) return false;
    else i+= 2;
  }
  return true;
}

module.exports = isPrime;