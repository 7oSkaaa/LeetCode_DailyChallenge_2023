// Author: Abdullah Moemen

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        /*
         Firstly assume all peoples are town Judge
         every persons trusted in anthers one mark it as non town judges (1st condition), and increament number of trustud for trusted[i][1]

        based on:
        1- all pairs of trust are unique.
        2-the town judges trusts nobody.
        3- only one person that satisfies above conditions
         
        so answer will be the person that have extacly (n-1) votes and he is trusts no body
         owterwise there are no answer and return -1
        */
        vector<int>frq(n+1,0);
        vector<bool>vis(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            vis[trust[i][0]]=1;
            frq[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])if(frq[i]==n-1)return i;
        }
        return -1;
    }
};