// Author: Lama Salah

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // Find the next greater letter of the target character in the vector
        // using the upper bound function.
        int idx = upper_bound(letters.begin(), letters.end(), target) - letters.begin();

        // If 'idx' is less than the vector's size, 
        // return the character at 'idx' (the next greatest character).
        // Otherwise, return the first character in the 'letters'.
        return letters[idx < letters.size() ? idx : 0];
    }
};