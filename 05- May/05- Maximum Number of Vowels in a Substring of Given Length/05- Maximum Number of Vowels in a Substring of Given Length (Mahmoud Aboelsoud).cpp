// Author: Mahmoud Aboelsoud

class Solution {
public:
    int maxVowels(string s, int k) {
        // to solve this problem we will use sliding window technique
        // we will keep track of the number of vowels in the current window
        // and we will keep track of the maximum number of vowels in a substring of given length

        // mx: maximum number of vowels in a substring of given length
        // vows: number of vowels in the current window
        // l: left pointer of the window
        int mx = 0, vows = 0, l = 0;

        // loop over the string, i is the right pointer of the window
        for(int i = 0; i < s.size(); i++){
            // if the current character is a vowel, we will increment vows
            vows += (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u');

            // if the size of the current window is equal to k, we will update mx and decrement vows and move l to the right
            if(i - l + 1 == k){
                mx = max(mx, vows);
                vows -= (s[l] == 'a' || s[l] == 'e' || s[l] == 'o' || s[l] == 'i' || s[l] == 'u');
                l++;
            }
        }

        // return the maximum number of vowels in a substring of given length
        return mx;
    }
};
