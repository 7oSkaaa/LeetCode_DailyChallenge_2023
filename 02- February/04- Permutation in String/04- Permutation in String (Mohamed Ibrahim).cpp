//Author: Mohamed Ibrahim
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Create a map to store the count of characters in s1
        map<char,int>mp;
        // Increment the count of the character in mp
        for (char ch : s1) mp[ch]++;
        for (int i = 0, j = 0; j <s2.size(); ++j) {
            // Decrement the count of the character in mp
            mp[s2[j]]--;
            // Slide the window i to the right until all characters in the window are valid
            while (i <= j && mp[s2[j]] < 0) 
                // Increment the count of the character
                mp[s2[i++]]++;
            // If the size of the current window is equal to the length of s1, return true
            if (j-i+1 == s1.size()) return true;
        }
        // Return false if no permutation of s1 is found in s2
        return false;
    }
};
