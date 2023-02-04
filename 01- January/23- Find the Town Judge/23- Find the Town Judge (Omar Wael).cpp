// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // frequancy array to count number of people that you trust them
        int freqa[1001]={0};
        // frequancy array to count number of people trust you
        int freqb[1001]={0};
        for(int i=0;i<trust.size();i++){
            freqa[trust[i][0]]++;
            freqb[trust[i][1]]++;
        }
        for(int i=1;i<=1000;i++){
            // if current person doesnot trust anybody and everyone trust him then he is the judge
            if(freqa[i]==0 && freqb[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};