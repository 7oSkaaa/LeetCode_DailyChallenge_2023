// Author: Ahmed Gamal

// for this problem we can count the number of zero-filled subarrays by counting the number of zeros in a row (biggest number of zeros in a row) and calculate number of subarrays it contains
// if we look at an array, we can see that the number of subarrays it conains is equal to the sum of the numbers from 1 to the size of the array
// why? if we have an array of size 3, we can have 3 subarrays: [1], [2], [3], [1, 2], [2, 3], [1, 2, 3]
// notice: 1 array of size 3, 2 arrays of size 2, 3 arrays of size 1
// we start from taking the whole array and there's only one way to do that, then we take an array of less size and as we decrease the size by one we increase the number of ways to take the array
// the least size of the subarrays we can take is 1, so we have 3 ways to take an array of size 1

// so to solve this problem, we can count the number of zeros in a row and calculate the number of subarrays it contains
// if we encounter a zero, we increase the number of zeros in a row by one, otherwise we reset it to zero

// we will use a little trick in calculating the number of subarrays it contains
// as we increase the number of zeros in a row by one, then we will add this size to the answer, consider this example:
// [0, 0, 0] -> we have 3 zeros in a row, as we are looping from left to right, we will increase the counter by one, so it will be 1, then we will add it to the answer
// after that, we will increase the counter by one, so it will be 2, then we will add it to the answer
// after that, we will increase the counter by one, so it will be 3, then we will add it to the answer
// so we will add 1, 2, 3 to the answer, which is the sum of the numbers from 1 to 3 (it's the same as calculating the size and applying the formula to it in the end)

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // ans: the number of zero-filled subarrays
        long long ans = 0;

        // cnt: the number of zeros in a row
        int cnt = 0;

        // loop over the array
        for(auto& i : nums) {
            // if we encounter a zero, we increase the number of zeros in a row by one (i == 0 evaluates to true if i is zero, otherwise it evaluates to false)
            cnt += i == 0;

            // if we encounter a non zero, we reset the number of zeros to zero (multiply by zero -> the expression evaluates to zero)
            cnt *= i == 0;

            // add the number of zeros in a row to the answer
            ans += cnt;
        }

        return ans;
    }
};