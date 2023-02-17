// Author: Lama Salah

class Solution {
public:
    bool detectCapitalUse(string word){
        int cnt = 0; // counter for counting uppercase letters
        for (auto& i : word)
            if (isupper(i)) cnt++; // count all uppercase letters

        if (!cnt|| cnt == word.size() || (cnt == 1 && isupper(word[0]))) return true;
        /* Check the counter value : 
            if it is equal to 0, it means that all letters in the given string are lowercase,
	        if it is equal to the size of a given string, it means that all letters in the given string are uppercase,
	        and check if it is equal to 1 and the first letter in the given string is uppercase.
	        all these cases are valid,
            Otherwise, return false.
	    */
        return false;
    }
};

