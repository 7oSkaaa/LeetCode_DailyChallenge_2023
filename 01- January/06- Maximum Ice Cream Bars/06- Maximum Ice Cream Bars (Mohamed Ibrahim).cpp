//Author: Mohamed Ibrahim
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
         sort(costs.begin(), costs.end());
    
    // Initialize a counter for the number of ice cream bars purchased
    int cnt = 0;
    
    for (int i : costs) {
        // If the boy has enough coins to buy this ice cream bar, add it to   the count and subtract its cost from the boy's coins
        if (coins - i >= 0) {
            cnt++;
            coins -= i;
        }
        // If the boy does not have enough coins, return the number of ice cream bars purchased
        else  return cnt;
        
    }
    // Return the total number of ice cream bars purchased
    return cnt;
    }
};