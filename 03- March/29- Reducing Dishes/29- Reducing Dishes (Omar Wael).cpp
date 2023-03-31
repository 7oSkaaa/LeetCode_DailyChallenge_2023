// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int dp[501][501];
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp,-1,sizeof(dp));
        int n=satisfaction.size();
        // sort dishes
        sort(satisfaction.begin(),satisfaction.end());
        return max(0,rec(satisfaction,0,n,1));
    }
    int rec(vector<int>& satisfaction, int i,int& n,int cnt){
        if(i>=n){
            return 0;
        }
        int &ret=dp[i][cnt];
        // check if current dish is visited before with same cnt
        if(~ret){
            return ret;
        }
        // check if current dish is negative 
        // then try to not take it
        if(satisfaction[i]<0){
            ret=max(ret,rec(satisfaction,i+1,n,cnt));
        }
        // try to take current dish
        ret=max(ret,rec(satisfaction,i+1,n,cnt+1)+(satisfaction[i]*cnt));
        return ret;
    }
};
