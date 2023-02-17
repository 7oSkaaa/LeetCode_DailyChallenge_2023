// Author: Omar Wael

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // create vector to split the words on it
        vector<string>v;
        string t="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                v.push_back(t);
                t.clear();
                t="";
            }else{
                t=t+s[i];
            }
        }
        v.push_back(t);
        int n=v.size();
        // check if the number of words not equal the number of characters in pattern 
        // the number of words and the number of characters in pattern should be equal 
        if(n!=pattern.size()){
            return false;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // if there are two positions have same char in pattern but not have the same word in the vector or
                // if there are two positions have same word in the vector but not have the same char in pattern 
                if((pattern[i]==pattern[j] && v[i]!=v[j]) || (pattern[i]!=pattern[j] && v[i]==v[j])){
                    return false;
                }
            }
        }
        return true;
    }
};