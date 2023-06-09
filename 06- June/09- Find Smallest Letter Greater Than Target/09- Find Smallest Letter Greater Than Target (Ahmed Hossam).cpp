// Author: Ahmed Hossam

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // Get the size of the vector
        int n = letters.size();
        
        // Find the upper bound of the target letter in the vector and calculate its index
        // If the index exceeds the size of the vector, wrap around to the beginning
        int idx = (upper_bound(letters.begin(), letters.end(), target) - letters.begin()) % n;
        
        // Return the next greatest letter
        return letters[idx];
    }
};
