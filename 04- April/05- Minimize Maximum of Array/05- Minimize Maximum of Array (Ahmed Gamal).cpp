// Author: Ahmed Gamal

// for this problem, we want to find the minimum value of the maximum element in the array after performing some operations
// if we looked at the operations, we can see that we can perform the operation in reverse order
// why? because the operation is subtracting 1 some number of times and adding the sum of the operations to the previous element
// so, we can use binary search to find the minimum value by trying all possible values of the maximum element
// and applying the operations in order to keep all elements less than or equal to the current value
// if we can do that, then we can try to decrease the value and check if we can still keep all elements less than or equal to the current value again

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        // left: maximum value that we can't achieve
        // right: minimum value that we can achieve
        long long left = -1, right = 1e11;

        // good: check if we can achieve the current value
        auto good = [&](long long mid) -> bool {
            // cpy: copy of the array to apply the operations on (we don't want to modify the original array)
            vector<long long> cpy(nums.begin(), nums.end());

            // iterate over the array in reverse order
            for(int i = cpy.size() - 1; i; --i) {
                // if the current element is greater than the current value
                if(cpy[i] > mid) {
                    // apply the operation (cpy[i] - mid) times
                    cpy[i - 1] += cpy[i] - mid;
                }
            }

            // return true if the first element is less than or equal to the current value (because the operations are applied in reverse order)
            return cpy[0] <= mid;
        };

        while(left < right - 1) {
            long long mid = left - (left - right) / 2;

            if(good(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return right;
    }
};