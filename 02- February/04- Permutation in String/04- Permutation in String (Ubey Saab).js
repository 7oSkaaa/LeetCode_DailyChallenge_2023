//Author : ubey Saab 





var checkInclusion = function(s1, s2) {
  //create an array from s1
  let arr1=s1.split('')
  // define l1 which is the length of s1
  let l1=s1.length
  // if s1 taller than s2  return false because s2 cannot include some string taller than itself
  if(s1.length>s2.length)
  {
      return false 
  }
  //if strings equals true
  else if(s1==s2){
      return true
  }
  else{
    //else we will using slidingWindow algorithm
      for(let i=0;i<s2.length;i++){//big for 
          let counter=0//define conter that will increase if number of element in arr1 and test is the same 
          let test=s2.slice(i,i+l1).split('')//creating our window with length of s1 the start and the end point will increase with i
// permutation : means  the both strings should have the same length and the same character frequencies
          //  for that reason we create the test window then we now try to figure out if the character frequecies are same 
          for(let j=0 ;j<test.length;j++){
            //arr1 is s1 converted to array 
            // if number of element in arr1 and test is the same 
              if(arr1.filter(x=>x==test[j]).length== test.filter(x=>x==test[j]).length){
                  counter++ //increase the counter

              }
              else{//if not the same go to the next index with big for 
                  break;
              }
          }
          if(counter==l1){
            //if counter equal to s1.length 
              return true
          }
          


      }
      // when all option above faild that mean there is no permutation
      return false 

  }
  
};
console.log(checkInclusion('ab','eidaboo'))