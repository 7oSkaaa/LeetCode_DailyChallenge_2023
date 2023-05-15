// author: Ahmed Gamal

// for this problem, we can use dynamic programming to find the maximum number of uncrossed lines
// we can use the same idea of knapsack problem, we either make a line from the current element or not
// if we make a line, we need to find the next element in the other array that is equal to the current element
// if we don't make a line, we just move to the next element in the current array
// and since we don't want to let these lines cross, we need to keep track of the last index we used in the other array
// we can find the next index using binary search

class Solution {
    // MX: maximum value of an element in nums1 or nums2
    // N: maximum size of nums1 or nums2
    // indexes: array of vectors to store the indexes of each element in nums2
    // memo: memoization array
    // n, m: size of nums1 and nums2
    static const int MX = 2005, N = 505;
    vector<int> indexes[MX];
    int memo[N][N];
    int n, m;

    // dp[idx][prv] = maximum number of uncrossed lines if we are at index idx in nums1 and the last index we used in nums2 is prv
    int dp(int idx, int prv, vector<int>& nums) {
        // base case
        if(idx >= n) {
            return 0;
        }

        // if we already calculated this state, return it
        int& ret = memo[idx][prv + 1];
        if(~ret) {
            return ret;
        }

        // don't make a line
        ret = dp(idx + 1, prv, nums);

        // make a line if possible
        auto& vec = indexes[nums[idx]];
        auto it = upper_bound(vec.begin(), vec.end(), prv);

        // if we can make a line, take the maximum between the two options
        if(it != vec.end()) {
            ret = max(ret, 1 + dp(idx + 1, *it, nums));
        }

        return ret;
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // n: size of nums1
        // m: size of nums2
        n = int(nums1.size());
        m = int(nums2.size());

        // initialize memo with -1
        memset(memo, -1, sizeof memo);
        
        // clear indexes array (we need to do this because the same array is used for all test cases)
        for(int i = 0; i < MX; i++) {
            indexes[i].clear();
        }

        // fill indexes array with the indexes of each element in nums2
        for(int i = 0; i < m; i++) {
            indexes[nums2[i]].emplace_back(i);
        }

        // call dp function with idx = 0 and prv = -1 (to be able to use upper_bound function)
        return dp(0, -1, nums1);
    }
};