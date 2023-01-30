// Author: Noura Algohary
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // corner case
        if(n==1)
            return 1;

        vector<int>trusts(n+1, 0); // if the person [i] trusts anybody
        vector<int> trusted(n+1, 0); // count how many the person [i] is trusted 

        for(int i=0; i<trust.size();i++)
        {
            trusts[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }

        auto max = max_element(trusted.begin(), trusted.end()); //find the most trusted count
        int num = distance(trusted.begin(), max); // find the most trusted person (index of the most trusted count)
   
        if(*max == n-1 && trusts[num] == 0) // the number of trusted count is equal to n-1 and the same person doesn't trust anyone
            return num;
            
        return -1;
    }
};