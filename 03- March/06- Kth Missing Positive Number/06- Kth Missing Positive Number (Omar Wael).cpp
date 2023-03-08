// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size();
        // i will make binary search to get the kth mising element
        // and the number of mising elements untill this element will be the difference between 
        // the element it self and it's index
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] - 1 - mid < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l + k;
    }
};