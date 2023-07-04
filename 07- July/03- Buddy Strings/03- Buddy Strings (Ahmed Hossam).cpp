// Author: Ahmed Hossam

class Solution {
public:
    bool buddyStrings(const string& s, const string& goal) {
        // if the two strings aren't the same size
        if(s.size() != goal.size())
            return false;

        // Create a frequency array to count the occurrence of each character in the first string.
        vector < int > freq(26);
        
        // Variable to store the count of characters that appear more than once in the first string.
        int is_same = 0;

        // 2D vector to store the differences between characters of the two strings.
        vector < int > diffs;
        
        // Iterate through each character in the first string.
        for(int i = 0; i < s.size(); i++){
            // Update the frequency array for the current character.
            freq[s[i] - 'a']++;
            
            // If the characters at the same index in the two strings are different,
            // add them to the differences vector.
            if(s[i] != goal[i])
                diffs.push_back(i);
            
            // Update the count of characters that appear more than once in the first string.
            is_same += (freq[s[i] - 'a'] > 1);
        }
        
        // If there are more than two differences, it is not possible to make the strings equal by swapping two characters.
        if(diffs.size() > 2 || diffs.size() == 1)
            return false;

        // If there are no differences, check if there are characters that appear more than once in the first string.
        if(diffs.empty())
            return is_same;

        // Check if the characters to be swapped are the same in the two differences.
        for(int i = 0; i < 2; i++){
            if(s[diffs[i]] != goal[diffs[!i]])
                return false;
        }

        // If all conditions are satisfied, it is possible to make the strings equal by swapping two characters.
        return true;
    }
};
