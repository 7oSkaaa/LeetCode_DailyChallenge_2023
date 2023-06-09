// Author: Ahmed Gamal

// for this problem, we will solve it using binary search in O(log(n)) time complexity
// we will use the fact that the letters are sorted in non-decreasing order

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // left: the index of the first letter that is less than or equal to the target
        // right: the index of the first letter that is greater than the target
        int left = -1, right = letters.size() - 1;

        // binary search
        while(left < right - 1) {
            // mid: the middle index
            int mid = (left + right) >> 1;
            if(letters[mid] > target) {
                // if the middle letter is greater than the target, then the answer is in the left half
                right = mid;
            } else {
                // if the middle letter is less than or equal to the target, then the answer is in the right half
                left = mid;
            }
        }

        // if the right index is out of range, then the answer is the first letter
        char c = letters[right];

        return c > target ? c : letters.front();
    }
};