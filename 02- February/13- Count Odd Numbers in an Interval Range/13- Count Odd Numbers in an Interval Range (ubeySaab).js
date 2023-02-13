// Author : ubey saab

 
var countOdds = function(low, high) {
  let counter=0; //declaring a counter to count the odd numbers inside the range we declare it here so once the function is called the first value should be zero .
  //  starting fro from low to high which should be inside the for so we used <=
    for(let i =low ;i<=high;i++){
        // odd number mod 2 ==1 
        if(i%2==1){ 
          // if the  number odd 
            counter++;
          //  increase the counter 

        }
    }
    return counter
    
};

console.log(countOdds(3,7))