// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to minimize the maximum value of the array
    // so we will use binary search to find the minimum value of the maximum value

    int minimizeArrayValue(vector<int>& nums) {

        // we will use a function to check if our maximum value is less than or equal to m    
        auto good = [&](int m){
            // we will make a copy of the array
            vector<long long> cpy(nums.size());
            for(int i = 0; i < nums.size(); i++) cpy[i] = nums[i];
            
            // we will add the carry to the next element
            long long carry = 0;
            // we will start from the end of the array
            for(int i = cpy.size() - 1; i > 0; i--){
                // we will add the carry to the current element
                cpy[i] += carry;
                // we will update the carry to be the maximum between 0 and the current element minus m
                carry = max(0ll, cpy[i] - m);
            }
            // we will add the carry to the first element
            cpy[0] += carry;

            // we will return true if the first element is less than or equal to m
            // which means that we can make the maximum value of the maximum value of the array not greater than m
            return cpy[0] <= m;
        };

        // we will use binary search to find the minimum value of the maximum value
        int l = 0, r = 1, best = -1;
        while(!good(r)) r *= 2;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(good(m)) r = m - 1, best = m;
            else l = m + 1;
        }

        // we will return the minimum value of the maximum value
        return best;
    }
};
