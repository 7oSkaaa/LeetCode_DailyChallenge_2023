// Author: Mahmoud Aboelsoud

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // we need to find the number of subarrays that have a minimum value of minK and a maximum value of maxK
        // to do that we use sliding window technique and we keep track of the last position of appearance of minK and maxK
        // to count the number of subarrays we use the following formula (min(mn, mx) - l + 1) where l is the left pointer of the sliding window
        // and mn and mx are the last positions of appearance of minK and maxK respectively
        // if the current element is less than minK or greater than maxK we reset the sliding window and mn and mx to -1
        // and we start the sliding window from the next element

        // imagine the following array [2, 5, 3, 1, 2, 4, 7] and minK = 1 and maxK = 5
        // by eye we can see that there are 6 subarrays that have a minimum value of 1 and a maximum value of 5
        // which are [2, 5, 3, 1], [2, 5, 3, 1, 2], [2, 5, 3, 1, 2, 4], [5, 3, 1], [5, 3, 1, 2], [5, 3, 1, 2, 4]
        // to calculate the number of subarrays we use the following formula (min(mn, mx) - l + 1) while looping through the array
        // you find the first time the minK and the maxK appears together in the current window will be at position 3 (0-based indexing)
        // you can see that the number of subarrays at this position is 2 which can be calculated by (min(1, 3) - 0 + 1) = 2
        // then you find the second time the minK and the maxK appears together in the current window will be at position 4 (0-based indexing)
        // you can see that the number of subarrays at this position is 4 which have two subarrays that are already counted in the previous position
        // so you only have 2 new subarrays which can be calculated by (min(1, 4) - 0 + 1) = 2
        // and so on you find that the number of new subarrays can be calculated by (min(mn, mx) - l + 1) where l is the left pointer of the current sliding window
        // and if the current element is less than minK or greater than maxK you reset the sliding window and mn and mx to -1
        // because you cannot find new subarrays that have a minimum value of minK and a maximum value of maxK in the current window anymore 

        // initialize the answer to 0
        long long ans = 0;
        // initialize the left pointer of the sliding window to 0, the last position of appearance of minK to -1, and the last position of appearance of maxK to -1
        int l = 0, mn = -1, mx = -1;

        // loop through the array
        for(int i = 0; i < nums.size(); i++){
            // if the current element is equal to minK update the last position of appearance of minK to the current position
            if(nums[i] == minK) mn = i;
            // if the current element is equal to maxK update the last position of appearance of maxK to the current position
            if(nums[i] == maxK) mx = i;

            // if the current element is less than minK or greater than maxK reset the sliding window and mn and mx to -1
            if(nums[i] < minK || nums[i] > maxK) mn = mx = -1, l = i + 1;

            // if the minK and maxK appeared together in the current window update the answer
            if(mn != -1 && mx != -1)
                // the number of subarrays that have a minimum value of minK and a maximum value of maxK in the current window is (min(mn, mx) - l + 1) 
                ans += min(mn, mx) - l + 1;
        }

        // return the answer
        return ans;
    }
};
