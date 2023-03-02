//Author : Ubey Saab



var singleNonDuplicate = function(nums) {
  for (let i=0;i<nums.length;i++){
    //if element equal to the next element increasing i so in this case i will increase 2 index at time one from for and one from the if condition  
      if(nums[i]==nums[i+1])
      {
          i++//
      }
      else{
        // if not equal to the next that mean is the single element so return it 
          return nums[i]
      }
  }

  
};
console.log(singleNonDuplicate([1,1,4,4,2]))