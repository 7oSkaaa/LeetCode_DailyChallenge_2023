// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        // if p.size > s.size 
        // then there are not any anagrams
        if(p.size()>s.size()){
            return ans;
        }
        // two vectors to count the frequency of each letter on each string 
        // v1 -> p
        // v2 -> s
        vector<int>v1(26,0),v2(26,0);
        // count frequency of p
        for(int i=0;i<p.size();i++){
            v1[p[i]-'a']++;
        }
        // n = p.size
        // declare two pointers 
        // one at first char at s 
        // the another one at nth char at s
        int p1=0,p2=p.size()-1;
        // count frequency of first n chars in s
        for(int i=0;i<p.size();i++){
            v2[s[i]-'a']++;
        }
        // if th=0 -> the n chars between p1 and p2 on s are anagram of p 
        int th=0;
        while(p2<s.size()){
            th=0;
            // check if frequency of p and current n chars on s are equal
            // if equal add p1 to the answer
            for(int i=0;i<26;i++){
                if(v1[i]!=v2[i]){
                    th=1;
                    break;
                }
            }
            if(th==0){
                // add p1
                ans.push_back(p1);
            }
            // if not remove first element and add another one (n+1th char) 
            v2[s[p1]-'a']--;
            p1++;
            if(p2==s.size()-1){
                return ans;
            }
            // add the new char 
            p2++;
            v2[s[p2]-'a']++;
        }
        return ans;
    }
};