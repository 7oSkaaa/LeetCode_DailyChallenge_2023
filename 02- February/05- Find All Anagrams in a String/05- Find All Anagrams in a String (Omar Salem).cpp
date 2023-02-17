//Author : Omar Salem
//Time Complexity :  O(n)
//Space Complexity : O(1)
class Solution {
public:
   
    vector<int> findAnagrams(string s, string p) {
        // intialize varible 
        int l = 0,r = 0;
        int n = s.size() , m = p.size();
        vector < int >  occ(26) , curOcc(26) ,ans;

        // build hashmap
        for(auto &i : p)
            occ[i -'a'] ++;

        while(r < n)
        {
            // increase the frequency of the letter that just enters the window
            curOcc[s[r] - 'a']++;
            // decrease the frequency of the letter that is out of the window
            if((r-l) >= m)
                curOcc[s[l++] - 'a']--;
            // check if the first window is an anagram of p
            if(occ == curOcc)
                ans.push_back(l);
            r++;
        }
        // return answer 
        return ans;
    }
};