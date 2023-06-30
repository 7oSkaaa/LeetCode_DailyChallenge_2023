// Author: Emad Mohamed
class Solution {
    // dp is the length of the longest subsequence starting from index i with difference between each element j. k denotes whether the sequence has started or not
    int dp[1000][1005][2];
    // To store the indices of each element in the input array  
    vector<vector<int>>indices; 
    // Function to find the first element with value toFind that comes after the current idx using binary search
    int findNxtIdx(int idx, int toFind){ 
        if(toFind < 0 || toFind > 500)
            return -1;
        int l = 0, r = indices[toFind].size() - 1, ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            (indices[toFind][mid] > idx ? (ans = indices[toFind][mid], r = mid - 1) : l = mid + 1);
        }
        return ans;
    }
    int findSeq(int idx, int diff, bool start, vector<int>& nums){
        if(idx == nums.size())
            return 0;
        int& ret = dp[idx][diff][start];
        if(~ret) return ret;
        ret = 0;
        //If we haven't started yet we should have the option to continue without starting
        if(!start)
            ret = findSeq(idx + 1, diff, start, nums);
        // The next element will be nums[idx] + diff but we should -500 which we added in the for loop in the original function (line 42)
        int nxtIdx = findNxtIdx(idx, nums[idx] + diff - 500);
        // We will take the current element and go to the next index with value nums[idx] + diff if it exists
        ret = max(ret, 1 + (~nxtIdx ? findSeq(nxtIdx, diff, 1, nums) : 0));
        return ret;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        indices.resize(1501);
        for(int i = 0; i < n; i++)
            indices[nums[i]].push_back(i);
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        // We will try every possible value of difference and +500 to avoid accessing negative elements
        for(int diff = -500; diff <= 500; diff++)
            ans = max(ans, findSeq(0, diff + 500, 0, nums));
        return ans;
    }
};
