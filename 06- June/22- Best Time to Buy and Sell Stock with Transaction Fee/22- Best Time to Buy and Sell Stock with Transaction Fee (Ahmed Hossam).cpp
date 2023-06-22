// Author: Ahmed Hossam

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // Get the number of prices in the vector.
        int n = prices.size();
        
        // Initialize variables for cash (available funds) and hold (stock held).
        // Set the initial value of hold to the negative of the first stock price.
        int cash = 0, hold = -prices[0];
        
        // Iterate through the prices starting from the second price.
        for(int i = 1; i < n; i++){ 
            // Calculate the maximum of either keeping the cash as it is or selling the stock and deducting the fee.
            cash = max(cash, hold + prices[i] - fee);
            
            // Calculate the maximum of either keeping the hold as it is or buying the stock and deducting the cash.
            hold = max(hold, cash - prices[i]);
        }
        
        // Return the maximum profit (cash) after all transactions.
        return cash;
    }
};
