// Author: Ahmed Gamal

// for this problem, we need just to implement any sorting algorithm to sort the array
// the problem asks us to use O(nlogn) time complexity and smallest possible space complexity
// so we can use merge sort to sort the array in O(nlogn) time complexity and O(n) space complexity (it is not the smallest possible space complexity)
// we can also use quick sort to sort the array in O(nlogn) time complexity and O(logn) space complexity (it is the smallest possible space complexity)
// for the constraints of the problem, we can use counting sort to sort the array in O(n) time complexity and O(n) space complexity (it is the smallest possible time complexity) since the maximum value of the array is 5 * 10^4

// but I will implement merge sort


class Solution {
public:

    // merge function to merge two sorted subarrays (nums[l..mid] and nums[mid+1..r]) (conquer step)
    void merge(vector<int>& nums, int l, int mid, int r){
        // sorted array to store the sorted subarray of nums[l..r]
        vector<int> sorted(r - l + 1);

        // i: index of the first subarray
        // j: index of the second subarray
        // idx: index of the sorted array
        int i = l, j = mid + 1, idx = 0;

        // while we have elements in both subarrays
        while(i <= mid and j <= r){
            int curr;
            if(nums[i] < nums[j]){
                curr = nums[i++];
            }else{
                curr = nums[j++];
            }
            sorted[idx++] = curr;
        }

        // if we have elements in the first subarray only
        while(i <= mid){
            sorted[idx++] = nums[i++];
        }

        // if we have elements in the second subarray only
        while(j <= r){
            sorted[idx++] = nums[j++];
        }

        // copy the sorted subarray to the original array
        idx = 0;
        for(int k = l; k <= r; k++){
            nums[k] = sorted[idx++];
        }
    }

    void merge_sort(vector<int>& nums, int l, int r){
        // base case (when we have only one element, it is already sorted)
        if(l == r)
            return;
        
        // divide the problem into two subproblems in half (divide step)
        int mid = l - (l - r) / 2;

        // call merge sort on the two subproblems recursively
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);

        // merge the two subproblems after sorting them
        merge(nums, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        // call merge sort with the original problem
        merge_sort(nums, 0, nums.size() - 1);

        return nums;
    }
};