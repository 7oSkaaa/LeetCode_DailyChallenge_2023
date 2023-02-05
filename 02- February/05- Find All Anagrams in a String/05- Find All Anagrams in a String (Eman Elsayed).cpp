// author : Eman Elsayed

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        map<char, int> mps, mpp; // mps to count number of characters in string s and mpp to string p
        for (int i = 0; i < p.size(); i++)
            mpp[p[i]]++, mps[s[i]]++;

        vector<int> ans;
        // check if first p.size characters of s is anagram for string p or not
        if (mpp == mps)
            ans.push_back(0);

        for (int i = p.size(); i < s.size(); i++)
        {
            mps[s[i - p.size()]]--; // remove the first character from the window
            if (mps[s[i - p.size()]] == 0)
                mps.erase(s[i - p.size()]); // if the frequency of the character is zero then remove it from the map
            mps[s[i]]++;                    // add the new character to the window
            if (mps == mpp)
                ans.push_back(i - p.size() + 1); // check if window is anagram for string p or not
        }
        // return the answer vector
        return ans;
    }
};