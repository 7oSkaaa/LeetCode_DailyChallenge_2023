// Author: Ahmed Hossam

class Solution {
public:
    // Define a type alias for long long
    typedef long long ll;

    long long maxRunTime(int n, vector<int>& batteries) {
        // Define a lambda function to check if given time x is sufficient
        auto is_good = [&](ll x){
            // Initialize variables for counting computers and current power
            ll computers = 0, curr_power = 0;
            // Iterate through each battery in the sorted order
            for(auto& b : batteries){
                // Add the current battery's power to the current power
                curr_power += b;
                // If the current power is greater than or equal to x,
                // it means we can run a computer, so decrement the current power and increase the computer count.
                if(curr_power >= x)
                    curr_power -= x, computers++;
            }
            // If the number of computers that can run is greater than or equal to n, return true
            return computers >= n;
        };

        // Sort the batteries in ascending order
        sort(batteries.begin(), batteries.end());

        // Initialize variables for binary search
        ll l = 1, r = 1e18, maxTime = -1;

        // Perform binary search to find the maximum run time
        while(l <= r){
            ll m = l + (r - l) / 2;
            // If is_good returns true, update the left pointer and store the current time as the maximum time
            (is_good(m) ? l = m + 1, maxTime = m : r = m - 1);
        }

        // Return the maximum run time
        return maxTime;
    }
};
