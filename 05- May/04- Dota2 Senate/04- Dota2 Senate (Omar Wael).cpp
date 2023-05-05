// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    string predictPartyVictory(string senate) {
        // r-> number of Radiant's senators
        // d-> number of Dire's senators
        // needtoremover -> number of banned senators but unremoved of type R 
        // needtoremoved -> number of banned senators but unremoved of type D
        int r=0,d=0,needtoremover=0,needtoremoved=0;
        queue<char>q;
        // push all senators inte queue
        // count senators in each party
        for(auto c:senate){
            q.push(c);
            if(c=='R'){
                r++;
            }else{
                d++;
            }
        }
        while(q.size()>1){
            // stop if no more senators of type R
            if(r==0){
                return "Dire";
            }
            // stop if no more senators of type D
            if(d==0){
                return "Radiant";
            }
            char c=q.front();
            q.pop();
            if(c=='R'){
                // check if current senator is banned
                if(needtoremover>0){
                    needtoremover--;
                    r--;
                }else{
                    // if not ban next senator of type D
                    needtoremoved++;
                    q.push(c);
                }
            }else{
                // check if current senator is banned
                if(needtoremoved>0){
                    needtoremoved--;
                    d--;
                }else{
                    // if not ban next senator of type R
                    needtoremover++;
                    q.push(c);
                }
            }
        }
        if(q.front()=='R'){
            return "Radiant";
        }else {
            return "Dire";
        }
        return "Radiant";
    }
};
