// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        // two vectors to count the frequency of each letter on each string 
        // v1 -> s1
        // v2 ->s2
        vector<int>v1(26,0),v2(26,0);
        // count frequency of s1
        for(int i=0;i<s1.size();i++){
            v1[s1[i]-'a']++;
        }
        // n = s1.size
        // declare two pointers 
        // one at first char at s2 
        // the another one at nth char at s2
        int p1=0,p2=s1.size()-1;
        // count frequency of first n chars in s2
        for(int i=0;i<s1.size();i++){
            v2[s2[i]-'a']++;
        }
        // if th=0 -> the n chars between p1 and p2 on s2 are Permutation of s1 
        int th=0;
        while(p2<s2.size()){
            th=0;
            // check if frequency of s1 and current n chars on s2 are equal
            // if equal return true
            for(int i=0;i<26;i++){
                if(v1[i]!=v2[i]){
                    th=1;
                    break;
                }
            }
            if(th==0){
                return true;
            }
            // if not remove first element and add another one (n+1th char) 
            v2[s2[p1]-'a']--;
            p1++;
            if(p2==s2.size()-1){
                return false;
            }
            // add the new char 
            p2++;
            v2[s2[p2]-'a']++;
        }
        return false;
    }
};