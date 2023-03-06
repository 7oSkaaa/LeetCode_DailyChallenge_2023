//Author : Ubey Saab
var sortArray = function(nums) {
    let len=nums.length// length of the array 
    if(len==1)
    {//if length equal to one return the array it self
        return nums
    }


    let mid =Math.floor(len/2)//find the mid point of the arry 
    let leftArr=nums.slice(0,mid) // make an subarray called leftArr that doesn't iclude the mid point 
    let rightArr=nums.slice(mid)// right array include the mid point 

    return merge(sortArray(leftArr),sortArray(rightArr))// return another fuction called merge inside of this funciton we call sortfun recursively
    
};

function merge(lAr,rAr)
//lar is left array ,rar right array 
{
     let ri=0// right index
     let li=0//left index
     let result=[]

     while(ri<rAr.length&& li<lAr.length)

     {

            if(lAr[li]<=rAr[ri])
            {
                result.push(lAr[li]) //push the smalles element to the new array  and increase the index of the array that include that smallest elemnt
                li++
            }
            else if(rAr[ri]<=lAr[li])
            {
                result.push(rAr[ri])//push the smalles element to the new array  and increase the index of the array that include that smallest elemnt
                ri++
            }
     }
    return result.concat(lAr.slice(li)).concat(rAr.slice(ri))// we use this line because, at the end of the process, one element is not included so we concatenate all arrays from the last index they have reached 

}