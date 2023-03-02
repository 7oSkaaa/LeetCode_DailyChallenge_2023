// author: Esraa Syam
class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r){
        int n1 = m - l + 1; // size of left subarray
        int n2 = r - m; // size of right subarray
        vector < int > L(n1), R(n2); 
        for(int i=0; i<n1; i++){
            L[i] = nums[l + i]; // copy left subarray
        }
        for(int i=0; i<n2; i++){
            R[i] = nums[m + 1 + i]; // copy right subarray
        }
        int i = 0, j = 0, k = l;
        while(i < n1 and j < n2){ // merge two subarrays
            if(L[i] <= R[j]){ // if left subarray element is smaller than right subarray element 
                nums[k] = L[i++]; // copy left subarray element to the original array
            }
            else{
                nums[k] = R[j++]; // copy right subarray element to the original array
            }
            k++; // move to the next element in the original array
        } 
        while(i < n1){
            nums[k++] = L[i++]; // copy the remaining elements in the left subarray
        }
        while(j < n2){
            nums[k++] = R[j++]; // copy the remaining elements in the right subarray
        }
    }
    void merge_sort(vector<int>& nums, int l, int r){
        if(l < r){
            int m = l + (r - l) / 2; // find the middle element
            merge_sort(nums, l, m); // call merge_sort on the left subarray
            merge_sort(nums, m + 1, r); // call merge_sort on the right subarray
            merge(nums, l, m, r); // merge the two sorted subarrays
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
