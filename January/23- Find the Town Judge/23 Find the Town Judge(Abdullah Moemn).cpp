//Author: Abdullah Moemn

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        /*
         firstly Assume  all people are town judges
         count number of trusted by others for each one

        based on:
        1-all pairs of trusted are unique
        2- trusted[i][0]!=trusted[i][1]

        exactly one person satisfy above condition so if there is a person have exactly n-1 trusts and not trusted in another person, he is Town judges.
        otherwise there is no Town judges.
        */
       
        vector<bool>vis(n+1,0);  
        vector<int>frq(n+1,0); 
        
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