// Author : Hamza Hassanain
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (m && nums[m] == nums[m - 1])
            {
                if ((r - m) % 2)
                    l = m + 1;
                else if ((m - 1 - l) % 2)
                    r = m - 2;
            }
            else if (m < nums.size() - 1 && nums[m] == nums[m + 1])
            {
                if ((r - (m + 1)) % 2)
                    l = m + 2;
                else if ((m - l) % 2)
                    r = m - 1;
            }
            else
                return nums[m];
        }
        return nums[l];
    }
};