//Author : Ubey Saab
var searchInsert = function(nums, target) 
{

  // in comments midvalue is Math.floor(nums.length /2)
    let copyNums=[]//creating an copy of nums 
    // find the midvalue in nums  if target smaller than it 
    if(target<nums[Math.floor(nums.length /2) ])
    {
      // copy will equal nums from  until mid value we made copy include the midvalue because may be the target value smalller than mid value bu great than mid value -1
        copyNums=nums.slice(0,Math.floor(nums.length /2)+1)
        for(let i =0 ;copyNums.length ;i++)
        { //now searching the index if target value smaller or equal than current index return the index
            if(target<=copyNums[i])
            {
                return i
            }

        }
    }
    // if target equal to the mid value return num[midvalue ]
    else if (target ==nums[Math.floor(nums.length /2) ])
    {
        return Math.floor(nums.length /2)

    }
    else{
          // copy equal from midvalue until nums.length
          copyNums=nums.slice(Math.floor(nums.length /2))
        for(let i =0 ;copyNums.length ;i++)
        {
          //now searching the index if target value smaller or equal than current index return the index + nums.length /2
            if(target<=copyNums[i])
            {
                return i+Math.floor(nums.length /2)
            }
            // if the target bigger than copynums element and i in the last index that mean the element not in array and we should adding  index 
            else if(target > copyNums[i]&& i==((copyNums.length))-1)
            {
                 return i+Math.floor(nums.length /2)+1 //+1 mean adding new index

            }

        }

    }
    
};
console.log(searchInsert([1,3,5,6],5))
console.log(searchInsert([1,3,5,6],8))
