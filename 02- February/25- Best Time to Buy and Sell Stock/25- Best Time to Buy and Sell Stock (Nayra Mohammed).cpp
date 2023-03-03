// Author: Nayra Mohammed

class Solution
{
public:
    /*
        - For every prefix, We calculate the difference between current element "the current end of the prefix" and the minimum element in it
          & the maximum calculated profit is our answer. 
    */
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, mn = 1e9; //ans-> store the maximum profit| mn-> store minimum element for current prefix

        /*
            for every new end of our prefix,we update our minimum and calculate the profit between it and current element
        */
        for (auto it : prices) 
            mn = min(mn, it), ans = max(ans, it - mn);

        return ans; //return max profit
    }
};
