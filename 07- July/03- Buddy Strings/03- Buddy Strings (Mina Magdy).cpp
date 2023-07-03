// Author: Mina Magdy

class Solution {
public:
    // Function to check if two strings can be made equal by swapping at most two characters
    bool buddyStrings(string s, string goal) {
        // Initialize frequency arrays for characters in both strings
        vector<int> freq1(26), freq2(26);
        // Variable to track if there are duplicate characters in 's'
        bool dup = false;
        
        // Calculate frequencies of characters in 's' and check for duplicates
        for (auto& c : s) {
            freq1[c - 'a']++;
            dup |= freq1[c - 'a'] > 1;
        }
        
        // Calculate frequencies of characters in 'goal'
        for (auto& c : goal)
            freq2[c - 'a']++;
        
        // Check if frequencies of characters in 's' and 'goal' are equal
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        
        // Check if the strings have exactly two different characters or
        // if the strings have no differences but contain duplicate characters
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
            cnt += s[i] != goal[i];
        
        return cnt == 2 || (cnt == 0 && dup);
    }
};
