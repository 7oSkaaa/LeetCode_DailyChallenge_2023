// Author: Ahmed Gamal

class Solution {
public:

    // for this problem, we will use a sliding window of size p.size() to check if the characters in the window are an anagram of p
    // we will use two vectors to store the frequencies of the characters in the window and p
    // every time we move the window, we will update the frequencies of the characters in the window and check if there is a match
    // if there is a match, we will add the index of the first character in the window to the answer vector

    vector<int> findAnagrams(string s, string p) {
        // if the size of s is less than the size of p, then there is no way that s contains an anagram of p
        if(s.size() < p.size())
            return {};

        // freq_a will hold the frequencies of the characters in p
        // freq_b will hold the frequencies of the characters in the window
        vector<int> freq_a(26), ans;
        auto freq_b = freq_a;

        // fill freq_a with the frequencies of the characters in p
        for(auto& i : p){
            freq_a[i - 'a']++;
        }

        // fill freq_b with the frequencies of the characters in the first window
        int l = 0, r = 0;
        while(r - l + 1 != p.size()){
            freq_b[s[r++] - 'a']++;
        }

        // loop until we reach the end of s
        for(; r < s.size(); r++){
            // add the frequency of the current character to freq_b
            freq_b[s[r] - 'a']++;

            // check if freq_a and freq_b are equal
            if(freq_a == freq_b)
                ans.emplace_back(l);
            
            // remove the frequency of the first character in the window from freq_b
            freq_b[s[l++] - 'a']--;
        }

        // return the answer vector
        return ans;
    }
};