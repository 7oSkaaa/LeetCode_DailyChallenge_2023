// Author: Ahmed Hossam

class Solution {
public:

    // define a string that contains vowels
    string vowels = "aeoiu";

    // function to check if a character is a vowel
    bool is_vowel(const char& c){
        return count(vowels.begin(), vowels.end(), c);
    }

    // function to find the maximum number of vowels in a substring of length k in a given string
    int maxVowels(const string& s, int k){
        // initialize variables to keep track of the current number of vowels and the maximum number of vowels seen so far
        int cnt_vowels = 0, max_vowels = 0;
        
        // define lambda functions to add and remove characters from the current substring and update the vowel count
        auto add = [&](const char& c){
            cnt_vowels += is_vowel(c);
        };
        auto remove = [&](const char& c){
            cnt_vowels -= is_vowel(c);
        };
        
        // iterate over the string
        for(int i = 0; i < s.size(); i++){
            // add the current character to the substring and update the vowel count
            add(s[i]);
            
            // if the length of the substring is greater than k, remove the oldest character from the substring and update the vowel count
            if(i >= k)
                remove(s[i - k]);
            
            // update the maximum number of vowels seen so far
            max_vowels = max(max_vowels, cnt_vowels);
        }
        
        // return the maximum number of vowels seen in any substring of length k
        return max_vowels;
    }
};
