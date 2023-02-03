//Author : Nayra Mohammed

class Solution {
public:
        /* As all we can do is taking elements from the array once
           then we have 2 possibilities for maximum subarray sum:
            ^ the whole array sum  is maximum
            ^ we can delete from the whole sum the minimum subarray sum (Circular array)
          ---------------------------------------------------------------
          we will use Kadane’s Algorithm to find maximum subarray sum and use the same logic to get minimum subarry sum
          References for kadane's algorithm
          
          ** https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
          
          ** https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
        */
  
    int maxSubarraySumCircular(vector<int>& nums) {
        //total to store the whole array sum
        // currmn to store current subarray sum to use it in getting minimum subarray sum
        // mn to store the updated minimum subarray sum initially with biggest value we can have
        // currmx to store current subarray sum to use it in getting maximum subarray sum
        // mx to store the updated maximum subarray sum
        int total = 0, currmn = 0 ,mn = 1e9, currmx = 0, mx = -1e9;
        
      
        for(auto it:nums){
            total += it; //add current element
            
           // here we get the maximum subarray sum
            currmx += it; //adding elements to currmx
            mx = max(mx, currmx); //maximize our final mx
            if(currmx < 0) // in case our currmx is less than zero that means adding either positive or negative in upcoming steps will make us get smaller values
                currmx = 0; //so we reset it to avoid getting smaller values.
           
           // And here we get the minimum subarray sum
            currmn += it; //adding element to currmn
            mn = min(mn, currmn); //minimize our final mn
            if(currmn > 0) // in case our currmn is bigger than zero that means adding either positive or negative in upcoming steps will make us get bigger values
                currmn = 0; //so we reset it to avoid getting bigger values.   
        }
        
        /*
        if our minimum subarray sum isn't equal to our total sum  then we can ignore that part of the array (delete minimum subarray sum from total) and
        and return the maximum between it and the maximum subarray sum normally.
        Otherwise, return maximum subarray sum.
        */
        return (mn != total)? max(total-mn, mx):mx;
    }
};
