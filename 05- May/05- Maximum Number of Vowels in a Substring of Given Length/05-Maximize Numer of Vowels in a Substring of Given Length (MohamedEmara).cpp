
// Author: MohamedEmara

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        /*
We will initially calculate number of vowels 
if the first k letters
then add character by character from end (of current segment)
and remove character by character from beginning (of current segment) in every step
        */

        int cntVowels = 0;
        for(int i=0; i<k; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i')
                cntVowels ++;
        }

        // track the number of vowels & maximize at each step
        int mx = cntVowels;

        for(int i=k; i<n; i++)
        {
            // if the new end is a vowel ---> increment cnt
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i')
                cntVowels ++;

            // if the old end is a vowel ---> decrement cnt
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'o' || s[i-k] == 'u' || s[i-k] == 'i')
                cntVowels --;
            
            mx = max(mx, cntVowels);
        }

        return mx;

    }
};



