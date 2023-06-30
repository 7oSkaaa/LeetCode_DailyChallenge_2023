// Author: Ahmed Gamal

// for this problem, we will use binary search to find the maximum value that can be placed at the given index
// obviously, if a value x is good, then all value less than x are also good
// we still need to find a way to check if a value x is good or not in fast way
// we will use the following observation:
// if we place a value x at the given index, then we can place x - 1 at the adjacent indices
// and we can place x - 2 at the adjacent indices of x - 1 and so on
// until we reach 1, so we can place 1 at all of the remaining indices

// now, we can check if a value x is good or not in O(1) time using some math formulas and the above observation

// we will use the following formula to calculate the sum of the first x numbers:
// sum(x) = x * (x + 1) / 2 (this is a well known formula, you can prove it using induction)

// let's say that we want to place a value x at the given index
// we will calculate the number of remaining slots for the left and right sides of the given index
// then we will first try to place x - 1, .. 1 at x - 1 slots of one side and fill the remaining slots with x
// to calculate the number of remaining slots for one side, we will use the following formula:
// rem = max(0, i - (x - 1)) where i is the number of remaining slots for this side

// now, we will calculate the sum of the numbers from x - 1 to 1 we are going to place at one side
// if we can place all the x - 1 numbers at one side, then the sum is sum(x - 1)
// but if we don't have enough slots, then we will place the largest numbers first
// the sum of the numbers we won't place is sum(x - 1 - i) where i is the number of remaining slots for this side
// so the sum of the numbers we are going to place is sum(x - 1) - sum(x - 1 - i)

// if all these numbers are less than or equal to the remaining sum, then x is good

class Solution {
    // we will use long long to avoid overflow
    typedef long long ll;

    // this function calculates the sum of the first x numbers
    ll sum(ll x) {
        return x * (x + 1) / 2;
    }

public:
    int maxValue(int n, int index, int maxSum) {
        // left and right are the bounds of the binary search (left is the largest good value and right is the smallest bad value)
        ll left = 0, right = 1;

        // this lambda function checks if a value x is good or not
        auto good = [&](ll x) -> bool {
            // rem is the remaining sum after placing x at the given index
            int rem = maxSum - x;

            // a and b are the number of remaining slots for the left and right sides of the given index
            int a = index, b = n - index - 1;

            // we will calculate the sums for both sides
            for(auto i : {a, b}) {
                // r is the number of remaining slots for this side (filled with ones)
                int r = max(0ll, i - (x - 1));

                // subtract the sum of the numbers we are going to place from the remaining sum
                // subtract them also from the remaining slots for this side
                rem -= r;
                i -= r;

                // if we have slots on this side, then subtract the sum of the numbers we won't place
                if(i) {
                    rem -= sum(x - 1) - sum(x - 1 - i);
                }
            }

            // if the remaining sum is non-negative, then x is good
            return rem >= 0;
        };

        // we will double the right bound until we find a bad value
        while(good(right)) 
            right <<= 1;

        while(left < right - 1) {
            ll mid = left - (left - right) / 2;

            if(good(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return left;
    }
};