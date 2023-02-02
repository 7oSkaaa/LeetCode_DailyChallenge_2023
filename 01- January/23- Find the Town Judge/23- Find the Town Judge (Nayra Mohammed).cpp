//Author: Nayra Mohammed

/*
All we need is to find a person who trusts noone and being trusted by all other people
(Act like we are in directed graph)
*/

#define sz(s) (int(s.size()))
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //trusts -> for each person counts the number of people they trust
        //trusted -> for each person counts how many people trust him
      
        vector<int>trusts(n+1),trusted(n+1);

        for(auto it:trust) //it-> {a,b} -> a trusts b
            trusts[it[0]]++,trusted[it[1]]++;

        for(int i=1;i <= n;i++) //iterate over all persons and check whether there exists a person who trust noone and being trusted by the all.
            if(!trusts[i] && trusted[i] == n-1)
                return i; //return his label

        return -1;    //otherwise we return -1 as we did find noone!
    }
};
