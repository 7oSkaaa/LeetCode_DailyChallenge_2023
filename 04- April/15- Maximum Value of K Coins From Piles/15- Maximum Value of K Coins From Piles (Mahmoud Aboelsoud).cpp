// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to maximize the sum of k coins from all the piles
    // at each pile we can take from 0 to min(k, pile.size()) coins
    // we use memoization to solve this problem


    // piles: the piles of coins
    vector<vector<int>> piles;

    // dp: memoization table
    int dp[1001][2001];

    // get_max: returns the maximum sum of k coins from all the piles
    int get_max(int idx, int k){
        // base case
        // if we have taken k coins
        // or we have reached the end of the piles
        // return 0
        if(!k) return 0;
        if(idx == piles.size()) return 0;

        // if we have already calculated the answer for this state return it
        if(dp[idx][k] != -1) return dp[idx][k];

        // sum: the sum of the coins we have taken from the current pile
        // ans: the answer for this state
        int sum = 0, ans = 0;

        // take 0 coins from the current pile
        ans = get_max(idx + 1, k);
        for(int i = 0; i < min(k, (int)piles[idx].size()); i++){
            // take i + 1 coins from the current pile
            sum += piles[idx][i];
            // update the answer
            ans = max(ans, sum + get_max(idx + 1, k - i - 1));
        }

        // return the answer
        return dp[idx][k] = ans;
    }   

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // set the piles
        this -> piles = piles;
        // initialize the memoization table with -1
        memset(dp, -1, sizeof(dp));

        // return the answer starting from the first pile and taking k coins
        return get_max(0, k);
    }
};
