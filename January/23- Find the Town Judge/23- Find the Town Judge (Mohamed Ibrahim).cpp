//Author: Mohamed Ibrahim

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // if there is only one person in the town, return 1
        if(n == 1) return 1;
        // create an array of size n+1 and initialize all values to 0
        vector<int> trustCnt(n+1, 0);

        // for each trust relationship, decrement the value of the person who trusts 
        // and increment the value of the person who is trusted
        for (auto t : trust) {
            trustCnt[t[0]]--;
            trustCnt[t[1]]++;
        }

        // iterate through the array
        for (int i = 1; i <= n; i++) {
            // check if there is exactly one person whose value is n-1 
            // (indicating that they are trusted by everybody else except themselves) 
            // and whose value in the trust array is not 0 (indicating that they trust nobody)
            if (trustCnt[i] == n-1 && trustCnt[i] != 0) {
                // return the label of the town judge if the town judge exists and can be identified
                return i;
            }
        }
        // otherwise return -1
        return -1;
    }
};
