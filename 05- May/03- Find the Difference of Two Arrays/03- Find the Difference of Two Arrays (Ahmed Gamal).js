// Author: Ahmed Gamal

// for this problem I will use two pointers technique to find the difference between two arrays
// since the order of the elements in the output array doesn't matter I will sort the two arrays to be able to use the two pointers technique
// to find if the current element in the first array is in the second array you can skip all the elements in the second array that are less than the current element
// and check if you reach the end of the second array or the current element in the first array is not equal to the current element in the second array
// and the next element will start from the last element you reached in the second array

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[][]}
 */
var findDifference = function(nums1, nums2) {
    // function to sort the array
    let sorted = nums => nums.sort((a, b) => a - b);

    // sort the two arrays
    nums1 = sorted(nums1);
    nums2 = sorted(nums2);


    // function to get the difference between two arrays
    let getDiff = (a, b) => {
        // i is the pointer for the second array
        // diff is the array that will contain the difference between the two arrays
        // last is the last element that was added to the diff array to avoid adding the same element more than once
        let i = 0, diff = [], last = -2000;

        // loop over the first array
        for(let j = 0; j < a.length; j++) {
            // skip all the elements in the second array that are less than the current element
            while(i < b.length && b[i] < a[j]) {
                i++;
            }
            // check if you reach the end of the second array or the current element in the first array is not equal to the current element in the second array
            if(i >= b.length || a[j] !== b[i]) {
                // check if the current element is not equal to the last element that was added to the diff array
                if(a[j] === last)
                    continue;

                // add the current element to the diff array
                diff.push(a[j]);
                last = a[j];
            }
        }

        return diff;
    };

    // return the difference between the two arrays and the difference between the second array and the first array
    return [getDiff(nums1, nums2), getDiff(nums2, nums1)];
};