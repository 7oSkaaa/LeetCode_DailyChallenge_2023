class Solution {
public:
      /**
    we will use minimum value, at first we will initialize it with INT_MAX and in each traversal we update it with the maximum between the previous minimum value and the current stock price. Now the profit will be equals maximum between the previous profit and the new profit which we can find by subtracting the minimum value from the current stock price.
    **/
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); // size of the array
        int res=0; // maximum profit
        int mn=INT_MAX; // minimum element 
        for(int i=0;i<n;i++){
            mn=min(mn,prices[i]); // get the minimum element 
                res=max(res,prices[i]-mn); // get the maximum profit by subtract each element from minimum element (mn)
        
        }
        return res; // return maximum profit 
        
    }
};