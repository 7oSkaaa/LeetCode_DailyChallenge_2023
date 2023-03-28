// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int dp[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        int n=days.size();
        return rec(days,costs,0,n,0);
    }
    int rec(vector<int>& days, vector<int>& costs,int i,int& n,int end){
        if(i>=n){
            return 0;
        }
        // check if current day is visited before
        if(~dp[days[i]]){
            return dp[days[i]];
        }
        int ret;
        // check if you must buy a new ticket
        if(days[i]>end){
            // get the index of first day after 7 days ticket finished
            // get the index of first day after 30 days ticket finished
            int week=n,month=n;
            for(int j=i+1;j<n;j++){
                if(days[j]>days[i]+6 && week==n){
                    week=j;
                }
                if(days[j]>days[i]+29 && month==n){
                    month=j;
                    break;
                }
            }
            // try to buy all types of tickets to find which is better
            // in 7 days ticket we will start from the first day after it finish not at i+1
            // same thing in 30 days ticket
            ret=min(rec(days,costs,i+1,n,days[i])+costs[0],min(rec(days,costs,week,n,days[i]+6)+costs[1],rec(days,costs,month,n,days[i]+29)+costs[2]));
        }else{
            ret=rec(days,costs,i+1,n,end);
        }
        return dp[days[i]]=ret;
    }
};
