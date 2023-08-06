// Author: Emad Mohamed
class Solution {
    // dp is the index in the array and the number of distinct elements that have been used so far
    int dp[101][101], mod = 1e9 + 7;
    int findCount(int idx, int used, int& n, int& goal, int& k){
        if(idx == goal)
            return used == n;
        int& ret = dp[idx][used];
        if(~ret) return ret;
        ret = 0;
        // If there are unused elements try to put them in this position
        if(n > used)
            ret += ((long long)(n - used) * findCount(idx + 1, used + 1, n, goal, k)) % mod;
        // Put a used element that wasn't used the last k times
        if(used > k)
            ret += ((long long)(used - k) * findCount(idx + 1, used, n, goal, k)) % mod;
        return ret %= mod;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp, -1, sizeof(dp));
        return findCount(0, 0, n, goal, k);
    }
};
