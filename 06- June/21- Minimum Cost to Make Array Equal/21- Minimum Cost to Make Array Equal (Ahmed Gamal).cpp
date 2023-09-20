// Author: Ahmed Gamal

// for this problem, we can see that the cost of each element is the absolute difference between the element and the target value
// and if we look at the effect of the value on the cost, we will find that the cost is decreasing until it reaches the target value then it starts to increase again
// so we can use ternary search to find the minimum cost
// we can see that the target value is between the minimum and maximum values in the array

class Solution {
    // nums is the array of numbers
    // cost is the array of costs
    vector<int> nums, cost;

    // this function returns the cost of making all elements equal to x
    long long f(int x) {
        long long res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res += 1ll * abs(nums[i] - x) * cost[i];
        }
        return res;
    }

    long long ternary_search(long long l, long long r) {
        // we will stop when the difference between l and r is less than 3 to avoid infinite loop
        while(r - l > 3) {
            // m1 is the first third of the range
            // m2 is the second third of the range
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;

            // f1 is the cost of making all elements equal to m1
            // f2 is the cost of making all elements equal to m2
            auto f1 = f(m1);
            auto f2 = f(m2);

            // if f1 is greater than f2, then the minimum cost is in the second third of the range
            if (f1 > f2)
                l = m1;
            else
                r = m2;
        }

        // we will try all values between l and r to find the minimum cost (less than or equal to 3 values)
        long long ans = LLONG_MAX;

        for(long long i = l; i <= r; i++) {
            ans = min(ans, f(i));
        }

        return ans;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        this -> nums = nums;
        this -> cost = cost;

        // get the minimum and maximum values in the array
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        return ternary_search(l, r);
    }
};