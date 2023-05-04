// Author : Salman Mohamed

class Solution {
public:
    string predictPartyVictory(string s) {
        
        bool found= true;
        stack<char>soso ;
        while(found){
            found =false;

            for(int i =0; i<s.size();i++){
                if(s[i]=='x')  continue;
                if(soso.empty()) {
                    soso.push(s[i]);
                    continue;
                }
                if(s[i]==soso.top()) soso.push(s[i]);
                else {
                    found=true;
                    s[i]='x';
                    soso.pop();
                }
            }
        }
        char ans ;
        for(auto i : s) if(i!='x') ans=i;
       if(ans=='R') return "Radiant";
       else return "Dire";
    }
};