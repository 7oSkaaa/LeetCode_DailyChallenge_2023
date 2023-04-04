// Author: Ahmed Gamal

// for this problem, we want to find the minimum number of partitions required to partition the string into substrings such that each substring is unique
// we can think of this problem greedily, we can iterate over the string and keep track of the frequency of each character
// if we find a character that has a frequency greater than 1, we can partition the string at the last index of this character
// otherwise, we can continue iterating over the string

class Solution {
public:
    int partitionString(string s) {
        // freq: frequency of each character
        vector<int> freq(26);

        // l: index of the leftmost character in the current substring
        // cnt: number of partitions required
        int l = 0, cnt = 0;

        // iterate over the string
        for(int r = 0; r < s.size(); r++) {
            // update the frequency of the current character
            freq[s[r] - 'a']++;

            // if the current character has a frequency greater than 1
            if(freq[s[r] - 'a'] > 1) {
                // partition the string at the last index of the current character
                // and remove the last substring from the current substring
                while(l < r) {
                    freq[s[l++] - 'a']--;
                }

                // update the number of partitions required
                cnt++;
            }
        }

        // take into account the last substring
        return ++cnt;
    }
};