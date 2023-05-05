// Author: Ahmed Gamal

// this is a trivial sliding window problem
// we will keep a window of size k and represent it by two pointers (l, r) where l points to the leftmost element in the window and r points to the rightmost element in the window
// and we will keep a variable cnt to count the number of vowels in the window
// we will start by moving the right pointer r until the size of the window is equal to k
// then we will loop over the string from r to the end of the string
// for each iteration we will check if the character at index r is a vowel or not
// if it is a vowel we will increase cnt by one
// then we will update the answer by max(ans, cnt)
// then we will move the left pointer l by one position to the right
// if the character at index l is a vowel we will decrease cnt by one

class Solution {
public:
    int maxVowels(string s, int k) {
        // cnt: number of vowels in the window
        // vowels: string that contains all the vowels
        int cnt = 0;
        string vowels = "aeiou";

        // check if the character c is a vowel or not
        auto check = [&](char c) -> bool {
            return ~vowels.find(c);
        };

        // move the right pointer r until the size of the window is equal to k
        int l(0), r(0);
        while(r - l + 1 != k) {
            if(check(s[r++])) {
                cnt++;
            }
        }

        // loop over the string from r to the end of the string
        int ans = 0;
        for(; r < s.size(); r++) {
            // if the character at index r is a vowel we will increase cnt by one
            if(check(s[r])) {
                cnt++;
            }

            // update the answer by max(ans, cnt)
            ans = max(ans, cnt);

            // move the left pointer l by one position to the right and if the character at index l is a vowel we will decrease cnt by one
            if(check(s[l++])) {
                cnt--;
            }
        }

        return ans;
    }
};