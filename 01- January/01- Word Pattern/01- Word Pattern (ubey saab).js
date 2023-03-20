//Author: Ubey Saab
var wordPattern = function (pattern, s) {
  // s can be taller than pattern so  we need to use sliding window with fixed size which is pattern.length
  // 2 we need to match frequencies and indexes 26.02.2023 now i know how to do with complexity o(n2)

  let start = 0;
  let arrayOfs = s.trim().split(" "); //trim to remove white spaces then splice for turn string to array
  let end = arrayOfs.length;

  let patternn = pattern.split(""); //turn pattern to array
  let patternIndexs = ""; //empty string
  let sindexs = ""; //empty string
  let flage = true;
  if (end == pattern.length) {
    //if end which is s.length and patterns length are equal
    while (start < end) {
      let i = 0;

      let target = arrayOfs[start]; //store the value of target
      let target2 = patternn[start]; //store the value of target
      patternIndexs += String(start); //adding the target value to string
      sindexs += String(start); //adding the 2nd target value to string
      while (i < end) {
        if (arrayOfs[i] == target && i != start) sindexs += String(i); // if the current index not equal to start and the element inside this index equal to our target add the index to the string
        if (patternn[i] == target2 && i != start) patternIndexs += String(i); // if the current index not equal to start and the element inside this index equal to our target add the index to the string
        i++; //increasing i
      }
      //when 2nd while finished compare if the indexes of our targets are the same so go to the next index
      if (sindexs === patternIndexs) flage = true;
      else return false; //if not return false

      start++; //increase the index
      patternIndexs = ""; // emptying the string
      sindexs = ""; // emptying the string for taking another target
    }
    return flage;
  } else {
    return false;
  }
};
