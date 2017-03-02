function check(number) {
  for(var i = 1; i < 20; i++) {
    if( number % i !== 0) {
      return false;
    }
  }
  return true;
}

function smallestValue20() {
  var search = true;
  var number = 20;
  while(search) {
    if(check(number)) {
      search = false;
      return number;
    }
    
    number += 20;
  }
}


smallestValue20();
