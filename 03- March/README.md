# LeetCode Daily Challenge Problems for March

<br><br>

## Workflow Checking

<div align="center">
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Author_Line.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Author_Line.yml" taget="_blank"/>
</img>
&nbsp;
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/File_Names.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/File_Names.yml" taget="_blank"/>
</img>
&nbsp;
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Daily_Problem.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Daily_Problem.yml" taget="_blank"/>
</img>
</div>

<br><br>

## Problems:

1. **[Sort an Array](#1--sort-an-array/)**

<hr>

<br><br>

## 1)  [Sort an Array](https://leetcode.com/problems/sort-an-array//)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Array` `Divide and Conquer` `Sorting` `Heap (Priority Queue)` `Merge Sort` `Bucket Sort` `Radix Sort` `Counting Sort`

### Code


```cpp
class Solution {
public:

    void Merge(int l, int m, int r, vector < int >& nums){
        // [l, m] and [m + 1, r] are sorted
        int sz_1 = m - l + 1, sz_2 = r - m;
        
        // left and right are temporary arrays
        
        vector < int > left(sz_1), right(sz_2);
        // copy the elements to the temporary arrays
        for(int i = 0; i < sz_1; i++) left[i] = nums[l + i];
        for(int i = 0; i < sz_2; i++) right[i] = nums[m + 1 + i];
        
        // merge the temporary arrays to be sorted array
        int i = 0, j = 0, k = l;
        while(i < sz_1 && j < sz_2)
            nums[k++] = (left[i] <= right[j] ? left[i++] : right[j++]);
        
        // copy the remaining elements
        while(i < sz_1) nums[k++] = left[i++];
        while(j < sz_2) nums[k++] = right[j++];
        // the array is now sorted
    }

    void Merge_Sort(vector < int >& nums, int l, int r){
        // base case is when the array has only one element
        if(l >= r) return;

        // divide the array into two parts
        int m = l + (r - l) / 2;

        // sort the two parts
        Merge_Sort(nums, l, m);
        Merge_Sort(nums, m + 1, r);

        // merge the two parts
        Merge(l, m, r, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        Merge_Sort(nums, 0, n - 1);
        return nums;
    }
};
```

<hr>

<br><br>
