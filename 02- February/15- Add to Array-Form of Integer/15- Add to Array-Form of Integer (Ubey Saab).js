// Author: Ubey Saab
var addToArrayForm = function(num, k) {
  // define carry 
  let carry=0
  //define an empty array
  let result=[]
  //define summation
  let summation;
  //make an array from k  and convert all elements to int 
  let kArray=String(k).split('').map(elem=>Number(elem))
  // take a differences between array's length 
  let dif =num.length -kArray.length
  // make an array and fill it with 0 from 0 index until diifferece between array's length that will leave some empty indexs 
  let bosArray=new Array(num.length).fill(0,0,dif).filter(elem=> elem!=null)
// cocatination the arrays above 
  bosArray=bosArray.concat(kArray)
  // console.log('_________________')
  // console.log(bosArray)
  // console.log(num)
  
//making swaping betwen k and num if k.length bigger than num 
  if(String(k).length>num.length)
  {
    let tmp =String(k).split('').map(elem=>Number(elem))
    k=Number(num.join(''))
    num=tmp
    // call addToArrayForm(again after swaping )
    return addToArrayForm(num,k)
  }

  else{
 

//  adding for loop to adding numbers index to index 
  for(let i =bosArray.length-1;i>=-1;i--)
    {
      summation =bosArray[i]+num[i]+carry

      // because we use decimal number :  if number bigger than 10 we 'll add the modulation of summation of 10 to the result array and let carry =1
      if(summation>=10){
        result.push(summation%10)
        carry=1
      }  
      // if not we push summation to result array and let carry=0
      else if(summation<10){
        result.push(summation)
        carry=0
    }
    // in the end when i =-1 that will give us an Nan so if carry bigger or equal to 1 we ll adding it to the result array 
    else{
        if (carry>=1){
            result.push(carry)
        }
    }
    }

  }
    // taking the reverst of result 
    result=result.reverse()
    return result
  
  
};
console.log(addToArrayForm([1,2,2,5,2,8,8,7,4,1,2,5,2,0,0,0,4,7,7,5,7,4,4,4,5,6,3,0,5,0],34))
console.log(addToArrayForm([0],35))