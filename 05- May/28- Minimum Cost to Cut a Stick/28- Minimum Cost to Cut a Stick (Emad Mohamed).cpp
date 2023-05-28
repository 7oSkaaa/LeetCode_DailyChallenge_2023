//Author: Emad Mohamed
class Solution {
    /*
    For this problem we can use ranged DP but 
    instead of l and r being the positions on the plane
    which is 1e6 * 1e6 we will use the indices of cuts 
    which is 100 * 100
    */
    int dp[105][105];
    int findMin(int l, int r, vector<int>& pos){
        // Base case is when there are no more cuts left in between l and r
        if(r - l == 1)
            return 0;
        int& ret = dp[l][r];
        if(~ret) return ret;
        ret = INT_MAX;
        // We cannot cut at l and r because these are the edges of the stick
        // So we can only cut in between them
        for(int cut = l + 1; cut <= r - 1; cut++)
            ret = min(ret, pos[r] - pos[l] + findMin(l, cut, pos) + findMin(cut, r, pos));
        return ret;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        // The array isn't always sorted
        sort(cuts.begin(), cuts.end());
        // We push 0 and n as the initial positions of cuts
        vector<int>pos = {0};
        for(auto &i : cuts)
            pos.push_back(i);
        pos.push_back(n);
        memset(dp, -1, sizeof(dp));
        return findMin(0, pos.size() - 1, pos);
    }
};
