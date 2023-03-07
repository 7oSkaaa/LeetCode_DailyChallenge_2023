// Author: Ahmed Gamal


// if we have a number x, we can find the number of missing numbers before x by subtracting the index of x in the array from x
// if the number of missing numbers before x is less than or equal to k, then we can say that the kth missing number is in the range [x, 2x]
// so we can use binary search to find the number x that satisfies the condition (x - index of x in the array <= k) and we want to find the maximum x that satisfies this condition
// we can find the index of x in the array by using lower_bound function (it returns the index of the first element that is greater than or equal to x)


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        // if the number of missing numbers before x is less than or equal to k
        auto good = [&](int x){
            // index of x in the array
            int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            
            // number of missing numbers before x
            return x - pos <= k;
        };

        // left: the maximum x that satisfies the condition (x - index of x in the array <= k)
        // right: the minimum x that satisfies the condition (x - index of x in the array > k)

        // if we are not sure about the minimum invalid x, we can set it to a large number 
        // but if this large number is too large, we may get a runtime error because of the overflow
        // so we can start with a small number and double it until we get a large enough number that is not valid (or valid depending on the problem)

        // start right with 1 to be able to double it
        int left = -1, right = 1;

        // double right until it is not valid (this loop will run at most log2(max_answer) times)
        while(good(right))
            right <<= 1;
            
        while(left < right - 1){
            int mid = left - (left - right) / 2;

            if(good(mid))
                left = mid;
            else
                right = mid;
        }

        return left;
    }
};