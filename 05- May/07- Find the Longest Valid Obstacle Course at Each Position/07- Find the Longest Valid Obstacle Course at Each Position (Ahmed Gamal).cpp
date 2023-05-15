// Author: Ahmed Gamal

// this problem requires us to find the length of the longest non-decreasing subsequence for each position in the array
// and since the array length is quite large (10^5) we can't use the naive O(n^2) solution
// one of the possible dp optimizations is to use binary search to find the position of the current element in the dp array (the dp array will be sorted)

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // n: number of elements in the array
        // d: dp array
        // ans: the answer
        const int n = (int)obstacles.size();

        // initialize the dp array with a very large value at each position
        vector<int> d(n + 1, 2e9);

        // add a very small value at the beginning of the dp array to avoid checking if the current element is the smallest element in the dp array
        // assume that the smallest element in the dp array is -2e9 and has a longest non-decreasing subsequence of length 0
        d[0] = -2e9;
        vector<int> ans;

        // loop over the array elements
        for(auto& i : obstacles) {
            // find the position of the current element in the dp array
            int pos = upper_bound(d.begin(), d.end(), i) - d.begin();

            // the position of the current element in the dp array is equal to the length of the longest non-decreasing subsequence for the current element
            ans.emplace_back(pos);

            // update the dp array
            d[pos] = min(d[pos], i);
        }

        // return the answer
        return ans;
    }
};