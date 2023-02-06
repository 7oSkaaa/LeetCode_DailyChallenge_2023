// author : Eman Elsayed

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int l = 0, r = n; // l to point to the first half of the array and r to point to the second half
        vector<int> ans;  // to store the answer
        while (r < 2 * n)
        {                           // loop until r reach the end of the array
            ans.push_back(nums[l]); // add the first element of the first half to the answer
            ans.push_back(nums[r]); // add the first element of the second half to the answer
            l++, r++;
        }
        // return the answer vector
        return ans;
    }
};