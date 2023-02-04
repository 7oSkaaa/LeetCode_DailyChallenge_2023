// Author: Ahmed Gamal

class Solution {
public:

    // We want to check if one string has a permutation of the other as a substring
    // if the string has a permutation of the other as a substring, then the substring will have the same size as the other string and the same frequency of characters
    // so we will use a sliding window of size s1.size() and check if the frequency of characters in the window is the same as the frequency of characters in s1
    // if the frequency is the same, then we have a permutation of s1 as a substring of s2
    // if the frequency is not the same, then we will move the window to the right by one character and check again
    // if the window reaches the end of s2 with no match, then we will return false

    // compare the frequency of characters in two strings
    bool check(vector<int>& freq_a, vector<int>& freq_b){
        for(int i = 0; i < 26; i++){
            if(freq_a[i] != freq_b[i])
                return false;
        }
        return true;
    }


    bool checkInclusion(string s1, string s2) {
        // if the size of s1 is greater than the size of s2, then s1 can't be a permutation of s2
        if(s2.size() < s1.size())
            return false;

        int l = 0, r = 0;
        // freq_a will hold the frequency of characters in s1
        // freq_b will hold the frequency of characters in the sliding window
        vector<int> freq_a(26);
        auto freq_b = freq_a;

        // fill freq_a with the frequency of characters in s1
        for(auto& i : s1)
            freq_a[i - 'a']++;

        // fill freq_b with the frequency of characters in the first window
        while(r - l + 1 != s1.size())
            freq_b[s2[r++] - 'a']++;

        // slide the window to the right and check if the frequency of characters in the window is the same as the frequency of characters in s1
        for(; r < s2.size(); r++){
            // add the new character to the window
            freq_b[s2[r] - 'a']++;

            // check if the frequency of characters in the window is the same as the frequency of characters in s1
            if(check(freq_a, freq_b))
                return true;
            
            // remove the first character from the window
            freq_b[s2[l++] - 'a']--;
        }

        
        // no match found
        return false;
    }
};