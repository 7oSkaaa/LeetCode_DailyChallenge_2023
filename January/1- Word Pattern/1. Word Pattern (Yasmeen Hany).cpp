// Author: Eileanora

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map <string ,char > mp;  //map to assign each word a character
        map <char , int> freq;   //map to check how many times character appeared
        for(auto& i : pattern)
            freq[i]++;

        s += ' ';
        int j = 0 , i = 0 , words = 0;
        string t , ans;
        for(i , j; i < s.size() && j < pattern.size(); i++)
        {
            if(s[i] != ' ') {
                t += s[i]; //if we didnt reach a space yet complete the word
                continue;
            }
            if(!isalpha(assigned[t]))   //if the word not assigned to a character yet
            {
                mp[t] = pattern[j];  //assign a character to it
            }
            else
                if(!(mp[t] == pattern[j]))  //if it's already assigned to a different character than the one in hand
                    return false;           

            t = ""; //reset t for a new word
            j++;    //move to another character of the pattern
            words++; //how many words in string s
        }
        vector <bool> check_chars(26 , 0); //bool to check if every vharacter was assigned to one word
        
        for(auto& [f , s] : mp)
        {
            if(v[s - 'a'] == true)  //if already assigned to another word -> return false
                return false;
            v[s - 'a'] = 1;          // mark assigned
        }
        // check if number of words = number of characters in the pattern and if we reached the end of both
        return ((freq.size() == mp.size()) && ((i == s.size()) && (j == pattern.size()) )); 
    }


};