// Author: Ahmed Hossam

class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        /*
            we will make BS on asnwer to get the kth missing number
            I try to make sequence of consecutive number it will be 
            - 1 2 3 4 5 6 7 8 9 .......
            my array will be 
            - 2 3 4 7 11

            i will try to check the second element in my array the difference between it
            and my second element in the sequence will be the number of missing elements
            untill this element

            if the answer will be -1 so the answer will be out of the array 
        */

        // the bounds of the search
        int n = a.size(), l = 1, r = n, ans = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            (a[m - 1] - m < k ? l = m + 1, ans = m : r = m - 1);
        }
        return ans + k;
    }
};
