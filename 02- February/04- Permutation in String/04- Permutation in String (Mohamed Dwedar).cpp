// Author: Mohamed Dwedar
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
            - The Goal this problem -> find if any substring of s2 is an anagram of s1
            - s1 and s2 will be anagrams if any one combination of s1 can form s2
            - conditions:
                - s1 and s2 must be equal length
                - s1 and s2 must having the same frequancy 
        */
        vector<int> str1(26 , 0);
        vector<int> str2(26 , 0);

        int len1 = s1.size();
        int len2 = s2.size();

        if(len1 > len2)
            return false;

        int ptr1 = 0 , ptr2 = 0;

        while(ptr2 < len1)
        {
            str1[s1[ptr2]-'a'] +=1;
            str2[s2[ptr2]-'a'] +=1;
            ptr2 +=1;
        }
        ptr2 -= 1;

        while(ptr2 < len2)
        {
            if(str1 == str2)
                return true;
            
            ptr2 += 1;
            if(ptr2 != len2)
                str2[s2[ptr2]-'a'] += 1;
            str2[s2[ptr1]-'a'] -= 1;
            ptr1 +=1;
        }
        return false;
    }
};