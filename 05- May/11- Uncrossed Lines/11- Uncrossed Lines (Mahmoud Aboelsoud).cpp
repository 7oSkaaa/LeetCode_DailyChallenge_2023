// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the maximum number of uncrossed lines
    // we can use 0/1 dp to solve this problem
    // we have two options at each step
    // 1- we can skip the current number of nums1
    // 2- we can take the current number of nums1 and try to find the first index of nums2 >= j that have the same value of nums1[i]
    // dp[i][j]: the maximum number of uncrossed lines between the first i numbers of nums1 and the first j numbers of nums2

    // ma: map to store the indices of each number in nums2
    map<int,vector<int>> ma;
    // nums1: the first array
    vector<int> nums1;

    // dp array
    int dp[501][501];

    // recursive function to find the maximum number of uncrossed lines
    int get_max(int i, int j){
        // if we reach the end of the first array we will return 0
        if(i == nums1.size()) return 0;

        // if we already calculated the answer for this state we will return it
        if(dp[i][j] != -1) return dp[i][j];

        // 1- we can skip the current number of nums1
        int ans = get_max(i + 1, j);

        // 2- we can take the current number of nums1 and try to find the first index of nums2 >= j that have the same value of nums1[i]
        auto it = lower_bound(ma[nums1[i]].begin(), ma[nums1[i]].end(), j);

        // if we found an index we will take it and add 1 to the answer
        if(it != ma[nums1[i]].end())
            ans = max(ans, 1 + get_max(i + 1, *it + 1));

        // memoize the answer and return it
        return dp[i][j] = ans;

    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // initialize dp array with -1
        memset(dp, -1, sizeof(dp));
        // store nums1 in a global variable
        this -> nums1 = nums1;

        // store the indices of each number in nums2 in a map
        for(int i = 0; i < nums2.size(); i++)
            ma[nums2[i]].emplace_back(i);
    
        // return the answer
        return get_max(0, 0);
    }
};
