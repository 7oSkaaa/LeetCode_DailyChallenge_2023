//Author : Ubey Saab

function addBinary (a,b){
  let result ='';
  if(a==b&&b==0)
  {

    result ='0'
    return result
  }
  //first define a string to store value 
  
  //2nd find the tolest number  or if the numbers length equal continue 
  
   else if(a.length>b.length ||a.length ==b.length)
  {
    // I tried this solutinon  based on the logic in the logic circuits. https://devreyakan.com/wp-content/uploads/2021/07/5IJBr.png
    let carry=0;
    let sum;
    // length difference : i used it to  leave number of digits empty the number of empty digits is the difference between length of the numbers  
    let lengthDifference=a.length-b.length
    let c =a.split('')//convert a to array
    let d=new Array(a.length).fill(0,0,lengthDifference)//fill the d array with zero from zero index to the differenceLength Note : differenceLength not included 
    // then addin d array to b which converted to array with split function then filter the empty indexs that i leave it in the previous step
    let e =d.concat(b.split('')).filter(elm=>{
      return elm!=null
    })
    c=c.map(elem=>Number(elem))//convert all index to numbers 
    e=e.map(elem=>parseInt(elem))// the same thing in step  above i just   wanna to refresh my js knowledge but there is a difference between those two covert way
  
    // make a loop starting from right to left  like adding operation 
    for ( let i =e.length-1;i>=-1;i--)
    {
      //in each step we adding the carry
      sum=e[i]+c[i]+carry 
    
      // if number bigger than 1 then we will adding sum mod 2 to the result and making  carry =1
      if(sum>1){
        
        result+=String(sum%2)
        carry =1
        
      }
      // if not, we 'll adding the sum like it is to the result and make carry 0
      else if(sum<=1){
       
        result+=String(sum)
        carry=0
      }
      // adding this case because -1 it's outOfindex so i just wanna be sure that i have been added the last carry
      else {
        if(carry==1)
          result+=String(carry)
           
      }
      
    }
   

  }
 
  // there you just doing swap to avoid write the reverse code of the code above again 
  else {
    let tmp=a 
    a=b
    b=tmp
    return addBinary(a,b)
  }
  result=result.split('').reverse().join('')
  return result

}

console.log(addBinary('11','1'));