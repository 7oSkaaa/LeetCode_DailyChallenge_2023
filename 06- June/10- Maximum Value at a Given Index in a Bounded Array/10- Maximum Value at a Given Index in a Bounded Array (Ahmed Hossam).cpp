// Author: Ahmed Hossam

class Solution {
public:
    
    int maxValue(int n, int index, int maxSum) {
        // function to calculate the sum of integers from 1 to x
        auto sum = [&](long long x){
            return x * (x + 1) / 2;
        };

        // function to check if the given value is good or not
        auto is_good = [&](long long m){
            long long arrSum = 0;

            // Calculate sum for the left segment
            arrSum = sum(m - 1);
            arrSum += (index > m - 1 ? index - m + 1 : -sum(m - 1 - index));

            // Calculate sum for the right segment
            arrSum += sum(m - 1);
            arrSum += (n - index > m ? n - index - m : -sum(m - n + index));

            // Check if the overall sum is less than or equal to maxSum
            return arrSum <= maxSum - m;
        };

        // Binary search to find the maximum value
        int l = 1, r = 1, ans = -1;

        // Get the boundary limit of r
        while(is_good(r))
            r *= 2;
        
        while(l <= r){
            int m = l + (r - l) / 2;
            (is_good(m) ? l = m + 1, ans = m : r = m - 1);
        }

        // Return the maximum value
        return ans;
    }
};
