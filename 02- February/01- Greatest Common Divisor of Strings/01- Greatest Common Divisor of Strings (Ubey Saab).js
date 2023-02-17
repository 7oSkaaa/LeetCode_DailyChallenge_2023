//Author : Ubey Saab 


var gcdOfStrings = function(str1, str2) {
const num =str1.length//take a length  of str1 which is gonna be the longest when in all states 
 let num1=str1.length// length of str1 that i will used in operations 
 let num2=str2.length//length of str2 


//if length of num1 > num2  I will do Euclidean Division  : web sites that help me to underStand https://www.dcode.fr/gcd
 if (num1>num2){
     while(num1%num2!=0){
      let tmp=num2
    
         num2=num1%num2
         num1=tmp
        
     }
    //  now num2 is the gcd of num1 and num2  i will repeat str2 from 0 until to num2 (which is the gcd)   num times : where  num is the length of str1 with out any changes divided by gcd if the repeated string == str1 and str1 include str2 which is a very needed option to passed test case 110th
     if(str2.slice(0,num2).repeat(num/num2)===str1 && str1.includes(str2)){
         return str2.slice(0,num2)//return  the common divisor 
     }
     else{
        // return ""
         return '""'
     }

 }
 else if(num1==num2){
    //if the number equal the gcd is the number it self 
      if(str2.slice(0,num2).repeat(num1/num2)===str1){
        return str2.slice(0,num2)
    }
    else{
        // if there no thing from options above return ''
        return '""'
    }
  
 }
 else{
    // swap do avoid reWrite the same code 
     let tmpr= str1
     str1=str2
     str2=tmpr
     return gcdOfStrings(str1,str2)
 }

};

// console.log(gcdOfStrings('ababab','ab'))
console.log(gcdOfStrings("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"))
