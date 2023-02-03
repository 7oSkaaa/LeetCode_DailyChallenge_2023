// Author: Mohamed Amr
int n;
class Solution {
public:
    // to store unique answers
    set<vector<int>>st;
    // to store each answer
    vector<int>temp;
    void func(int start, int prev, vector<int>& nums)
    {
        // base case if start index == the size of the array exit
        if(start == n)
        {
            return;
        }

        // if current element greater than prev element  or  if current subsequence is empty
            // take the current element
        // then pop it back (backtracking) (take it or leave it)
        if(!temp.size() || nums[start] >= prev)
        {
            temp.push_back(nums[start]); // take the element
            if(temp.size()>=2)
                st.insert(temp);
            func(start+1, nums[start], nums); 
            temp.pop_back();            // leave the element
        }
        
        func(start+1, prev, nums);      // recurse to the next element
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        func(0, 0, nums);
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};