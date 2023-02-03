// Author: Anas Maher

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char,string>mp; // to assign chars from the pattern to words from string s.
        unordered_map<string,bool>vis; 
        // to mark visited words in string s, for the test case : pattern = abba , s = cat cat cat cat , trace the following code with and without marking visited words and see the results.

        vector<string> words; // to store words.
        int psz = pattern.size();
        int wordCount=0; // number of words in s.
        stringstream ss(s); // to remove spaces.
        string w;

        while( ss >> w ) // while there is words..
        {words.push_back(w); wordCount++;} 
        
        if(psz!=wordCount) return false; // its obvious that the string cant be on the same pattern if it has number of words less or more than chars of the pattern string.

        for(int i=0 ; i<psz ; i++)
        {
            // if we didnt assign a word to this char, and this words wasnt assigned to any other char..
            if(mp.find(pattern[i])==mp.end() && vis.find(words[i])==vis.end()) 
            {
                mp[pattern[i]] = words[i]; // assign this word to this char.
                vis[words[i]] = 1; // mark the word visited (assigned).
            }

            // if we didnt assign a word to this char, but this word was assigned to another char..
            else if(mp.find(pattern[i])==mp.end() && vis.find(words[i])!=vis.end())
            {
                return false; // it cant be on the same pattern, no word should be assigned to 2 different chars.
            } 

            // if current char is assigned and current word is visited..
            else
            {
                if(mp[pattern[i]]!=words[i]) return false; // not on the same pattern
            }
        }

        return true; // if string s passed the 3 "false" cases, then its on the same pattern.
    }
};