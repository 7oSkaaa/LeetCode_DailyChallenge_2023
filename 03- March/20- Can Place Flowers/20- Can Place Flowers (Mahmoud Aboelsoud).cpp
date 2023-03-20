// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we can place flower in any empty spot if the previous and next spots are empty
    // so we can use dp to solve this problem
    // dp[i][j] = maximum number of flowers we can place if we start from i and the previous spot is j
    // j = 0 if the previous spot is empty
    // j = 1 if the previous spot is full
    // j = 2 if we are at the first spot

    // we can place flower in the current spot if the previous spot is empty and the current spot is empty
    // then at the next spot it must be empty so at that spot we check if placed flowe at it's previous spot or not
    // if yes then this will be an invalid state so we return -1e5

    // the input array
    vector<int> flowerbed;
    // the dp array
    vector<vector<int>> dp;


    // the function to calculate the dp
    int cnt_mx(int idx, int prev){
        // if we reached the end of the array then return 0
        if(idx == flowerbed.size()) return 0;

        // if the previous spot is full and the current spot is full then this is an invalid state
        if(flowerbed[idx] == prev && prev) return -1e5;

        // if we have calculated this state before then return the answer
        if(dp[idx][prev] != -1) return dp[idx][prev];

        // skip the current spot and keep the flowerbed as it is
        int ans = cnt_mx(idx + 1, flowerbed[idx]);

        // if the previous spot is empty and the current spot is empty then we can place flower in the current spot
        if(prev != 1 && flowerbed[idx] == 0)
            // caulate the maximum number of flowers we can place if we place flower in the current spot
            ans = max(ans, 1 + cnt_mx(idx + 1, 1));

        // store the answer and return it
        return dp[idx][prev] = ans;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // initialize the dp array
        dp.assign(flowerbed.size() , vector<int> (3, -1));
        // store the input array
        this -> flowerbed = flowerbed;

        // return true if the maximum number of flowers we can place is greater than or equal to n
        return cnt_mx(0, 2) >= n;
    }
};
