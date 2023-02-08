// Author: Mahmoud Aboelsoud

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // we will use sliding window technique to find all anagrams of string p in string s
        // we will use unordered_map to store the frequency of each character in string p
        // we will use another unordered_map to store the frequency of each character in the sliding window
        // we will use two pointers l and r to represent the left and right of the sliding window
        // we will use a vector to store the starting index of each anagram
        // we will iterate over string s from left to right
        // we will add the current character to the sliding window
        // if the current character is not in string p, we will clear the sliding window and move the left pointer to the next character
        // if the size of the sliding window is equal to the size of string p, we will check if the two unordered_maps are equal
        // if they are equal, we will add the left pointer to the vector
        // we will remove the left character from the sliding window and move the left pointer to the next character

        unordered_map<char, int> ma, window;
        // we will store the frequency of each character in string p in unordered_map ma
        for(auto&i: p) ma[i]++;
        // ans will store the starting index of each anagram
        vector<int> ans;
        // l will represent the left of the sliding window
        int l = 0;
        // we will iterate over string s from left to right
        for(int r = 0; r < s.size(); r++){
            // we will add the current character to the sliding window
            window[s[r]]++;
            // if the current character is not in string p, we will clear the sliding window and move the left pointer to the next character
            if(!ma.count(s[r]))
                window.clear(), l = r + 1;

            // if the size of the sliding window is equal to the size of string p, we will check if the two unordered_maps are equal
            if(r - l + 1 == p.size()){
                // if they are equal, we will add the left pointer to the vector
                if(ma == window) ans.push_back(l);
                // we will remove the left character from the sliding window and move the left pointer to the next character
                window[s[l++]]--;
            }
        }
        return ans;
    }
};
