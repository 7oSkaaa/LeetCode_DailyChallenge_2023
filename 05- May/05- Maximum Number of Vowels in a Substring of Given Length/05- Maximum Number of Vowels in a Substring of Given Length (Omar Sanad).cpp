// author : Omar Sanad

// As show in the code below its a simple fixed sliding window problem,
// where we have to move two pointers l and r and calculate the current number of vowels in the current window
class Solution {
public:
    int maxVowels(string s, int k) {
        
        // make a boolean array to mark all vowel letters
        bool Vowel[26]{};
        Vowel['a' - 'a'] = Vowel['e' - 'a'] = Vowel['i' - 'a'] = Vowel['o' - 'a'] = Vowel['u' - 'a'] = true;

        // declare the two pointers l and r, and n which is the length of the string s
        int l = 0, r = 0, n = s.size();

        // declare the current number of vowels in the current window
        int curVowels = 0;

        // calculate the current number of vowels in the first window
        for (; r < k; r++)
            curVowels += Vowel[s[r] - 'a'];

        // declare a variable to store the answer for the problem, 
        // and initialize it with the number of vowels in the first window
        int maxAns = curVowels;

        // move the fixed sliding window and update the current number of vowels in the current window,
        // also update the answer to the problem (Maximize the answer if possible).
        while (r < n) {
            curVowels -= Vowel[s[l++] - 'a'];
            curVowels += Vowel[s[r++] - 'a'];
            maxAns = max(maxAns, curVowels);
        }

        // return the answer to the problem
        return maxAns;
    }
};
