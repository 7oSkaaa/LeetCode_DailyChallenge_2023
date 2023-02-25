// author : Ahmed Zedan
class Solution {
public:
    vector<vector<int>>dp ; 
    vector<int>v ; 
    int n ; 
    /*
        - dp with two state (index of prices and buy or not
        - i(index of prices) , buy(determine buy stock (1) or not (0)) , stop(determine sell (1) or not (0))
    */
    int rec(int i=0 , int buy=0 , int sell=0){
        if(i>=n||sell) return 0 ; // base case : return 0 if i >= size of prices or already sell stock
        int &ret = dp[i][buy] ; 
        if(~ret) return ret ; 
        if(buy){ 
            ret = max(v[i]+rec(i+1,0,1),rec(i+1,1,sell)) ; 
        }
        else{
            ret = max(-v[i]+rec(i+1,1,sell),rec(i+1,0,sell)) ; 
        }
        return ret ; 
    }
    int maxProfit(vector<int>& prices) {
        v = prices ; 
        n = prices.size() ; 
        dp = vector<vector<int>>(n+5,vector<int>(2,-1)) ; 
        return rec() ; 
    }
};