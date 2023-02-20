// Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{
public:
    // - We gonna apply BS (aka.binary search algorithm) to find the index of minimum number bigger than our target as there our target will be located if it doesn't exist

    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = sz(nums) - 1, ans = sz(nums);
        /*
         - Our search space is between nums'indices [l, r] ~ [0, sz(nums)-1]
         - ans -> to store the appropriate index for target ,initially equals to nums'size in case all nums' elements are smaller than target

        */

        // Appling BS to find the minimum number bigger than our target 
        while (l <= r)
        {

            int m = l + ((r - l) >> 1);

            if (nums[m] > target)
                r = m - 1, ans = m;
            else
                l = m + 1;
        }
        /*
            - If there exists an element in the previous index of our answer "nums[our answer's - 1] "that equals to our target then we subtract one from ans
            Otherwise, We do nothing
         */
        return ans - (ans != 0 && nums[ans - 1] == target);
    }
};
