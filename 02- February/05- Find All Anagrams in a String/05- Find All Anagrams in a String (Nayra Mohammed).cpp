//Author : Nayra Mohammed 

#define sz(s) (int(s.size()))
class Solution
{
public:
    /*
        This problem is pretty similar to yesterday's one
        Here we gonna use the same technique "sliding window" over string s to check if current window is
        an anagram of string p.
        First, We need to keep with us the frequencies of p's characters as that's what matters rather than string p itself
        Second, We gonna made a fixed window over every possible start in string s with having the window's characters' frequencies
        If Window's characters' frequencies are identical to p's characters' frequencies 
        ,We save the starting index of that window as our answer
    */    
    vector<int> findAnagrams(string s, string p)
    {
        // mp1 -> to store p's characters' frequencies
        // mp2 -> to store current window's characters' frequencies
        // ans -> to store our valid starting indices final answer 
        vector<int> mp1(26), mp2(26), ans;
        
        for (auto it : p) // increase the frequency of each p's character
            mp1[it - 'a']++;

        
        for (int i = 0; i < sz(s); i++)
        {
            mp2[s[i] - 'a']++; //increase the frequency of current string s 's character 

            if (i >= sz(p) - 1) // if we made an actual window of size string p "anagrams same string with different arrangements"
            {   
                if (mp1 == mp2) // if we have identical frequencies between the two of them,we store the starting index
                    ans.push_back(i - sz(p) + 1);

                mp2[s[i - sz(p) + 1] - 'a']--; // remove the starting index's character from frequency "least recently added character"
                                               // to prepare for the upcomping window
                             
            }
        }

        return ans; // return the required answer 
    }
};
