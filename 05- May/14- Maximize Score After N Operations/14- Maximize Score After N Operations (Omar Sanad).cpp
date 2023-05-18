// author : Omar Sanad

class Solution {
public:
    // declare the array nums in the class itslef, to use it anywhere in the class
    vector < int > nums;

    // declare a 2D array for the memoization
    // declare the number of steps (n)
    // declare the size of the array which equals 2 * n
    int dp[15][1 << 14], n, the_sz;
    int rec(int idx, int mask) {
        
        // if we've already done the n operations, then we return
        if (idx > n)
            return 0;

        // assign the dp[idx][mask] to ret by reference to use it easily
        int &ret = dp[idx][mask];

        // if this state was already been calculated, then we return its answer
        if (~ret)   return ret;

        // otherwise we initialize the answer with 0
        ret = 0;

        // we iterate over the elements of the array, and for every two unvisited elements we try taking them for this step
        for (int i = 0; i < the_sz; i++)
            if ((mask & (1 << i)) == 0)
                for (int j = i + 1; j < the_sz; j++)
                    if ((mask & (1 << j)) == 0)
                        // if we try to take nums[i], nums[j]
                        // then we mark them as visited in the mask --> mask | (1 << j) | (1 << i)
                        ret = max(ret, idx * gcd(nums[i], nums[j]) + rec(idx + 1, mask | (1 << j) | (1 << i)));


        // return the answer for this state
        return ret;
    }
    int maxScore(vector<int>& nums) {

        // assign the passed array nums to the array nums which is declared inside the class itself
        this->nums = nums;

        this->the_sz = nums.size(); // the size of the array
        this->n = the_sz / 2;       // the number of operations to be done
        
        // initialize the array dp with -1, in other words mark as not calculated
        memset(dp, -1, sizeof(dp));


        // return the answer to the problem
        return rec(1, 0);
    }
};
