//Author: Ubey Saab

var detectCapitalUse = function (word) {
  //turn the string to array for using every function for compare elements one one
  if (word.split("").every((element) => element == element.toUpperCase()))
    return true;
  //turn the string to array for using every function for compare elements one one
  else if (word.split("").every((element) => element == element.toLowerCase()))
    return true;
  //if the word first character capital and the  remains is lower and its equal to word
  else if (word[0].toUpperCase() + word.slice(1).toLowerCase() == word)
    return true;
  else return false;
};

console.log(detectCapitalUse('USA'))
