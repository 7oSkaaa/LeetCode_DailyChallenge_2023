// Author: Ahmed Hossam

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Initialize two pointers l and r to the start and end of the array, and a variable ans to store the peak index
        int l = 0, r = arr.size() - 1, ans = 0;
        // Use a binary search algorithm to find the peak index
        while(l <= r){
            // Calculate the middle index using the l and r pointers
            int m = l + (r - l) / 2;
            // If the element at index m is greater than the element at index m+1, move r pointer to m-1 and update ans to m
            // This means that the peak is on the left side of m
            (arr[m] > arr[m + 1] ? r = m - 1, ans = m : l = m + 1);
        }
        // Return the peak index
        return ans;
    }
};
