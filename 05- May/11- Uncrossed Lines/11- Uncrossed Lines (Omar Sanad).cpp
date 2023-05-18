// author : Omar Sanad

class Solution {
public:
    // declare the nums1 in the class itself to be able to use it anywhere in the class
    vector < int > nums1;

    // declare an array of vectors, to store the indeces of each number in the array nums2
    vector < int > Idx[2002];

    // declare a 2D array for memoizing
    int dp[505][505];

    // the recurrsion function
    int rec(int i, int j) {

        // if we've finished all elements in nums1, then return
        if (i == nums1.size())  return 0;

        // assigns the dp[i][j] to ret by reference to use it in a fancy way
        int &ret = dp[i][j];

        // if this state have been already calculated, then no need to calculate it again, just return the stored value
        if (~ret)   return ret;

        // otherwise we will try the two possible ways : Take or Leave
        
        // Leave
        ret = rec(i + 1, j);

        // Take
        // here we check whether there is an element in nums2 that = nums1[i], and its position is >= j
        int idx = lower_bound(Idx[nums1[i]].begin(), Idx[nums1[i]].end(), j) - Idx[nums1[i]].begin();

        // if there is such element, then we take it
        if (idx < Idx[nums1[i]].size())
            ret = max(ret, 1 + rec(i + 1, Idx[nums1[i]][idx] + 1)); // note the new value of j will be (the position of element in nums2) + 1

        // return the dp[i][j] after maximizing the current state
        return ret;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // store all positions of the numbers in the array nums2
        for (int i = 0; i < nums2.size(); i++)
            Idx[nums2[i]].push_back(i);

        // initialize the dp with -1, mark as not calculated
        memset(dp, -1, sizeof dp);

        // assigns the passed vector nums1 to nums1 which is declared in the class itself
        this->nums1 = nums1;

        // return the answer to the problem
        return rec(0, 0);
    }
};
