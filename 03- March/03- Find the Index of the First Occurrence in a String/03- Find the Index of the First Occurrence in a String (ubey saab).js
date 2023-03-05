//Author : Ubey Saab 

// in this problem we use two pointer or sliding window ;

var strStr = function(haystack, needle) {
  let start=0// define start 
  let i=0 //define index pointer
  let counter=0//define counter
  while(i<needle.length&&start <haystack.length) //while i smaller than the small word that shoudl be contained in haystack and while start smaller than haystack
  {
    // i always should start from zero to compare the current index which is start with the first index from needle 
      if(haystack[start+i]!=needle[i])
      {//if haystack start +i index element not equal needle i index  element 
          start++ //start +1
          counter=0//counter = zero because maybe  the condition will be false at the middle 
          i=-1//because we increase it in the End of while 

      }
      else if(haystack[start+i]==needle[i])
      {
          counter++ //if equal increase the counter 
      }


      if(counter==needle.length)
      {
          return start //if counter equal to small word length return the start point 
      }

      i++
  

  }

  return -1//else return -1


};