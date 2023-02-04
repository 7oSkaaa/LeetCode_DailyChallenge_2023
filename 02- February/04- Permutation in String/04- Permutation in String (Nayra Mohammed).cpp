//Author :  Nayra Mohammed

#define sz(s) (int(s.size()))
/*
    To check whether s2 have a permutation(aka. different continuos arrangements) of s1
    - We gonna use fixed sliding window technique over string s2 to find a continuos part of it of size s1
      having same characters' frequencies as s1 does.
    - Reference : https://www.geeksforgeeks.org/window-sliding-technique/

*/
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {   
        /*
          mp1 -> to store s1's characters' frequencies
          mp2 -> to store s2's characters' frequencies for every s1.size() in s2
        */
        unordered_map<char, int> mp1, mp2;
        
        for (auto it : s1) //for each s1's character add it's frequency
            mp1[it]++;
        
        for (int i = 0; i < sz(s2); i++)
        {
            mp2[s2[i]]++; // add current character's frequency
            
            if (i >= sz(s1) - 1) // reaching or exceeding the required size means we made a new window of that size
            { 
                if (mp2 == mp1)// if both frequencies are identical then s2 has a permutation of s1 in current window
                    return true;

                //Otherwise, we need to remove the least recently added character from mp2
                //least recently added characte means we remove our actual start of current window
                // r(current end index) - l(least added character index"start index") + 1 = sz(s1)"window's size"
                if (mp2[s2[i - sz(s1) + 1]] == 1)
                    mp2.erase(s2[i - sz(s1) + 1]);
                else
                    mp2[s2[i - sz(s1) + 1]]--;
            }
        }

        // we are done searching, No permutation of s1 were found in s2
        return false;
    }
};
