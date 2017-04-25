function letterChanges(str) {
  let strArray = [...str];
  return strArray.map(letterShift).join('').replace(/[aeiou]/g, (e) => e.toUpperCase());
}


function letterShift(letter) {
  let charNum = letter.charCodeAt();
  return charNum > 97 && charNum < 122 ?  String.fromCharCode(charNum + 1) : String.fromCharCode(charNum)
}



letterChanges('fun times!');

//"gvO Ujnft!"
