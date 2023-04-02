// Author: Ahmed Gamal

// for this problem, we can use binary search to to implement what it asked for
// why binary search? because we want to find the minimum x (or k in the statement) that satisfies the condition (number of hours to eat all the bananas <= h)
// if we look at the search space, we can see that if we have a number x, which is not enough to eat all the bananas in h hours or less, then we can say that all numbers less than x are not enough to eat all the bananas in h hours or less
// and if we have a number x, which is enough to eat all the bananas in h hours or less, then we can say that all numbers greater than x are enough to eat all the bananas in h hours or less

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // if we have a number x, we can find the number of hours to eat all the bananas by dividing the number of bananas in each pile by x and rounding up
        // good(x) returns true if the number of hours to eat all the bananas is less than or equal to h
        auto good = [&](long long x) -> bool {
            // cnt: number of hours to eat all the bananas
            long long cnt = 0;
            for(auto& i : piles){
                // divide the number of bananas in each pile by x and round up (ceil)
                cnt += (i + x - 1) / x;
            }

            // return true if the number of hours to eat all the bananas is less than or equal to h
            return cnt <= h;
        };

        // left: the greatest x that does not satisfy the condition (number of hours to eat all the bananas <= h)
        // right: the smallest x that satisfies the condition (number of hours to eat all the bananas <= h)
        long long left = 0, right = 1;

        // because we are not sure about the suitable value of right, we can start with a small number and double it until we get a large enough number that is not valid (or valid depending on the problem)
        // this loop will run at most log2(max_answer) times
        // this also is a good way to avoid overflow
        while(not good(right))
            right <<= 1;
        
        while(left < right - 1){
            long long mid = left - (left - right) / 2;

            if(good(mid))
                right = mid;
            else
                left = mid;
        }

        return right;
    }
};