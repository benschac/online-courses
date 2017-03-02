function diff(n) {
  var sumsSquared = 0;
  var squaredSums = 0;
  
  for(var i = 0; i <= n; i++) {
    sumsSquared += Math.pow(i, 2);
  }
  
  for(var j = 0; j <= n; j++) {
    squaredSums += j;
  }
  
  squaredSums = Math.pow(squaredSums, 2);
  
  return squaredSums - sumsSquared;
}

diff(100);
