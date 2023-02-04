// Author: Omar Salem 
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //trusting -> number of person [i] trusting anybody
        //trusted ->  number of person [i] is trusted 
        vector<int> trusting(n+1,0), trusted(n+1,0);

        for(int i=0;i<trust.size();i++)
            trusting[trust[i][0]]++ ,trusted[trust[i][1]]++;

        int ans = -1;

        for(int i = 1; i <= n ; i++)
        //if person not trust any one and all person trust him
            if(trusting[i] == 0 && trusted[i] == n-1)
                ans = i;

        return ans;

    }
};