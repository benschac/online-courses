function isPalendrome(input) {
  var string = String(input);
  
  if(string.length === 1 || string.length === 0) {
    return true;
  }
  
  
  if(string[string.length -1] === string[0]) {
    return isPalendrome(string.substring(1, string.length - 1));
  } else {
    return false;
  }
  
}

function listOfValues() {
  var first = 999;
  var second = 999;
  var list = [];
  for(var i = first; i > 0; i--) {
    for(var j = second; j > 0; j--) {
      if(isPalendrome((j * i))) {
        list.push((j * i));
      }
      
    }
  }
  
  return list;
}

var palendromes = listOfValues();

function largest(arr) {
  var biggest = 0;
  
  arr.forEach(function(el) {
    if(el > biggest) {
      biggest = el;
    }
  });
  
  return biggest;
}

largest(palendromes);
