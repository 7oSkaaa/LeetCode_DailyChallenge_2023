// Author: Noura Algohary
//  Use sliding window 
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), vowelsCnt = 0;

        for(int i = 0; i < k ; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u')
                vowelsCnt++;

        }
        int maxVowels = vowelsCnt;
        for(int i = k; i < n; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u')
                ++vowelsCnt;

            if(s[i - k] == 'a' || s[i - k] == 'e' ||s[i - k] == 'i' ||s[i - k] == 'o' ||s[i - k] == 'u')
                --vowelsCnt;

            if(vowelsCnt > maxVowels)
                maxVowels = vowelsCnt;
        }
        return maxVowels;
    }
};