// Author: Ahmed Gamal


// for every element in the array, we have 2 elements with the same value except for one element and we have to find it
// if we have no restriction on the time complexity, we can use several methods to solve this problem
// such as but not limited to:
// 1- using a map to count the number of occurrences of each element (O(n) time if we use unordered_map (hash table) or frequency array if the values will fit, or O(nlogn) time if we use map (red-black tree))
// 2- sorting the array and then iterate over it to find the element with odd number of occurrences (if the array is not sorted, we can sort it first and then iterate over it) (O(nlogn) time) or O(n) time if we use counting sort
// 3- xor all the elements in the array and the result will be the element with odd number of occurrences (O(n) time)

// but we have a restriction on the time complexity, and we have to solve this problem in O(logn) time
// so we can use binary search to solve this it even faster than the previous methods
// we can use the following observation:
// if we are in the middle of an even index, the element at this index should be equal to the element at the next index
// if this is not the case, then the element with odd number of occurrences is to the left of the current index (because there is a corrupted pair of elements)
// we can use upper bound to find the length of the longest prefix of the array that contains only pairs of elements
// then the element with odd number of occurrences is the element at the index of the length of the longest prefix (left + 1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // n: length of the array
        const int n = int(nums.size());

        // left: index of the leftmost element in the array (initially -1 because we are using upper bound) (if there is no element with odd number of occurrences, then the element with odd number of occurrences is the element at index 0 (-1 + 1 = 0))
        // right: index of the rightmost element in the array (initially n because we are using upper bound and don't want right to be an obstacle for the left pointer)
        int left = -1, right = n;

        while(left < right - 1){
            int mid = left - (left - right) / 2;

            // should_be: if the element at the current index should be equal to the element at the next index
            int should_be = mid & 1 ? 0 : 1;

            // if the element at the current index and the element at the next index satisfy the condition, then the element with odd number of occurrences is to the right of the current index
            // otherwise, the element with odd number of occurrences is to the left of the current index
            if(mid < n - 1 and (nums[mid] == nums[mid + 1]) == should_be)
                left = mid;
            else
                right = mid;
        }

        // the element with odd number of occurrences is the element at the index of the length of the longest prefix (left + 1)
        return nums[left + 1];
    }
};