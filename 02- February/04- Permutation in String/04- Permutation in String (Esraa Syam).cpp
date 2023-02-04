// author: Esraa Syam
class Solution {
public:
    /*
        we want to know if we can find a permutation of s1 in s2
        so we can use a sliding window to check if the maps are equal wirh szie of s1
        solution  idea:
        1. create a map of s1 and s2
        2. check if the maps are equal if yes return true
        3. if not then slide the window and check if the maps are equal
        4. if yes return true
        5. if not return false
     */
    */
    bool checkInclusion(string s1, string s2) {
        // if the size of s1 is greater than s2 then return false
        if (s1.size() > s2.size()) return false;
        // create a map of s1 and s2
        map < char, int > m1, m2;
        // fill the maps with the characters frequency of s1 and s2
        for (int i = 0; i < s1.size(); i++) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if (m1 == m2) return true;
        int l = 0;
        // slide the window and check if the maps are equal
        for (int r = s1.size(); r < s2.size(); r++) {
            m2[s2[r]]++;
            m2[s2[l]]--;
            if(!m2[s2[l]) m2.erase(s2[l]);
            l++;
            if(m1 == m2) return true;
        }
        return false;
        
    }
};