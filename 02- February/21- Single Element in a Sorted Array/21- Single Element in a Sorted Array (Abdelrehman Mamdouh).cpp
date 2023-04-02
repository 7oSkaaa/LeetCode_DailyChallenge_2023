// Author : Abdelrehman Mamdouh
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int l = 0, r = nums.size() - 1;
        // two pointer method that moves if this element has a duplicate
        while (l < r)
        {
            if (nums[l] != nums[l + 1])
                return nums[l];
                
            if (nums[r] != nums[r - 1])
                return nums[r];
                
            // move two steps because we know that the adjacent element is eqaul thus not considering it in our calculations.
            l += 2, r -= 2;
        }
        // if the element is in the middle then l or r will be standing on it
        return nums[l];    
    }
};
