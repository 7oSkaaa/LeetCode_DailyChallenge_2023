// Author: Ahmed Gamal

// for this problem, we can use backtracking to try all possible ways to distribute the cookies
// we will try to put each cookie in each box and then try to distribute the rest of the cookies
// at the end we will take the minimum of the maximum sum of cookies in each box

class Solution {
    // sums[i] is the sum of cookies given to child i
    vector<int> sums;

    // idx is the index of the cookie we are trying to distribute
    // cookies is the vector of cookies
    // ans is the minimum of the maximum sum of cookies in each box
    void rec(int idx, vector<int>& cookies, int& ans) {
        // if we have distributed all cookies
        if(idx >= cookies.size()) {
            int mx = *max_element(sums.begin(), sums.end());
            ans = min(ans, mx);
            return;
        }

        // try to put the cookie in each box
        for(int i = 0; i < sums.size(); i++) {
            sums[i] += cookies[idx];
            rec(idx + 1, cookies, ans);
            sums[i] -= cookies[idx];
        }
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        // initialize sums and ans
        sums.assign(k, 0);
        int ans = 1e9;

        // start backtracking
        rec(0, cookies, ans);

        return ans;
    }
};