// Author: Ahmed Hossam

class Solution {
public:

    // make shortcut for long long
    #define ll long long

    int minimizeArrayValue(vector < int >& nums) {
        // Lambda function that takes an integer as input and returns a boolean value indicating whether the given integer is good or not.
        auto is_good = [&](ll m){
            // If the first element in the vector is greater than the given integer, it cannot be good.
            if(nums[0] > m) return false;
            ll last = nums[0];
            
            // Loop through the vector starting from the second element.
            for(int i = 1; i < nums.size(); i++){
                // Calculate the value to be removed from the previous element to make it less than or equal to the given integer.
                ll to_remove = m - last;
                
                // Calculate the new value for the current element after removing the calculated value from the previous element.
                last = nums[i] - abs(to_remove);
                
                // If the new value is greater than the given integer, it cannot be good.
                if(last > m) 
                    return false;
            }
            
            // All elements in the vector are less than or equal to the given integer, hence it is good.
            return true;
        };
        
        // Initialize the lower and upper bounds of the binary search.
        int l = 0, r = 1e9, ans = -1;
        
        // Binary search for the minimum good integer.
        while(l <= r){
            // Calculate the middle point.
            int m = l + (r - l) / 2;
            
            // If the middle point is good, update the upper bound and the answer.
            (is_good(m) ? r = m - 1, ans = m : l = m + 1);
        }

        // Return the minimum good integer.
        return ans;
    }

};
