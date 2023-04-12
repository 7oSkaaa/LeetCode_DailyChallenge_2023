// Author: Ibrahim Khalid
class Solution {
public:
    string removeStars(string s) {
        // store character's string in stack without stars accordings to opertions
        stack<char>t;
        for(int i=0;i<s.size();i++){
            // delete left character to star
            if(s[i]=='*'&&!t.empty()){
                t.pop();
            }
            else if(s[i]=='*'&&t.empty()){
                continue;
            }
            else{
                // store character which not after stars
                t.push(s[i]);
            }
        }
        string str="";
        while(!t.empty()){
            str+=t.top();
            t.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};