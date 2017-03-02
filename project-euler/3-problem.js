function isPrime(number) {
  if(number < 1 ) return false;
  if(number === 1 || number === 2) return true;
  if(number % 2 === 0) return false;
  
  for(var i = 3; i <= Math.sqrt(number); i+=2) 
    if(number % i === 0) return false;
  return true;
}

function primeList(upperbound) {
  var pList = [...Array(upperbound).keys()].filter(isPrime);
  return pList;
}

function primeFactoral1(number) {
  var list = primeList(50000);
  return list.filter((el) => number % el === 0);
}

primeFactoral1(600851475143);
