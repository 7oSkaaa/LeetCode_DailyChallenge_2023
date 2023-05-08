// Author: Ahmed Gamal

// this problem requires us to find the number of subsequences that satisfy the given sum condition (subsequences should have at least one element)
// we can find out how to construct the subsequences if we looked at the first example
// each number has a range of possible values that can be used with it to construct a valid subsequence
// if we suppose that the current number is the minimum number in the subsequence then the maximum number we can use with it is target - 3
// any larger number will make the sum larger than target
// so we can find the larger valid number from the position of the current number in the array using simple binary search (after sorting the array, since the order of the elements doesn't matter)
// then number of subsequences that can be constructed using the current number is equal to 2^(position of the larger valid number - position of the current number)

class Solution {
    // MOD: the modulo value
    // bin_exp: calculates the value of b^e % MOD in O(log(e))
    const int MOD = 1e9 + 7;
    int bin_exp(long long b, int e) {
        long long res = 1;
        while(e) {
            if(e & 1) {
                res = (res % MOD) * (b % MOD) % MOD;
            }
            b *= b;
            b %= MOD;
            e >>= 1;
        }
        return res;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        // n: number of elements in the array
        const int n = int(nums.size());

        // sort the array
        sort(nums.begin(), nums.end());

        // ans: the answer
        int ans = 0;

        // loop over the array elements
        for(int i = 0; i < n; i++) {
            // left: the position of the last element that can be used with the current element to construct a valid subsequence
            // right: the position of the first element that can't be used with the current element to construct a valid subsequence
            // rem: the maximum value that can be used with the current element to construct a valid subsequence
            int left = i - 1, right = n;
            int rem = target - nums[i];

            while(left < right - 1) {
                int mid = left - (left - right) / 2;

                if(nums[mid] <= rem) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            // if the position of the last element that can be used with the current element is greater than or equal to the position of the current element
            // then we can construct a valid subsequence using the current element
            if(left >= i) {
                ans += bin_exp(2, left - i);
                ans %= MOD;
            }
        }

        return ans;
    }
};