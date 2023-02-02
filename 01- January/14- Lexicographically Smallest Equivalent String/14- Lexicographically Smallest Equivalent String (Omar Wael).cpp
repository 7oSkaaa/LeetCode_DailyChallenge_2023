// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    // array to save the equivalent of each letter
    int equivalent[26];
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(equivalent,-1,sizeof(equivalent));
        // find best equivalent for each letter
        for(int i=0;i<s1.size();i++){
            Union(s1[i]-'a',s2[i]-'a');
        }
        // update base string 
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]='a'+find(baseStr[i]-'a');
        }
        return baseStr;
    }
    int find(int x){
        if(equivalent[x]==-1){
            return x;
        }
        // find best equivalent for x
        return equivalent[x]=find(equivalent[x]);
    }
    void Union(int x,int y){
        x=find(x);
        y=find(y);
        if(x!=y){
            // update the equivalent of the greater char to minimum char
            equivalent[max(x,y)]=min(x,y);
        }
    }
};