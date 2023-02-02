// Author: Mahmoud Aboelsoud

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        // the judge is the one who is trusted by everyone and he trusts no one
        // so we can make two frequency lists one for the number of people who trust each person and the other for the number of people each person trusts
        // if the frequency of the ones he trust is 0 and the frequency of the ones who trust him is n - 1 then he is the judge
        // if there is no judge return -1

        // two frequency lists one to count the number of people who trust each person and the other to count the number of people each person trusts
        vector<int> trusts(n + 1, 0), trusted(n + 1, 0);

        // loop on the trust list and update the frequency lists
        for(auto&i: trust)
            trusts[i[0]]++, trusted[i[1]]++;

        // loop on the frequency lists and check if the judge is found
        for(int i = 1; i <= n; i++){
            // if the frequency of the ones he trust is 0 and the frequency of the ones who trust him is n - 1 then he is the judge
            // then we return the judge index
            if(trusted[i] == n-1 && trusts[i] == 0) return i;
        }

        // otherwise there is no judge so we return -1
        return -1;
    }
};
