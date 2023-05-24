// Author: Esraa Syam
class Solution {
public:
    int maxVowels(string s, int k) {
        // lambda function to check if the char is vowel or not
        auto is_vowel = [](char c) { 
            return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';  
        };
        int n = s.size();
        int l = 0 , r = 0 , cnt = 0 , ans = 0;
        // use sliding window technique to get the maximum number of vowels
        for(; r < n; r++) {
            cnt += is_vowel(s[r]); // add the current char to the cnt if it's vowel
            if(r - l + 1 == k) { // if the window size is equal to k
                ans = max(ans , cnt); // update the answer
                cnt -= is_vowel(s[l++]); // remove the leftmost char from the cnt
            }
        }
        return ans;
    }
};