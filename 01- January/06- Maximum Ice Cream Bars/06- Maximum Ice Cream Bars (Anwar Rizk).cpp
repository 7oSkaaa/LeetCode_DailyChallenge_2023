// Author: Anwar Rizk

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Sort the costs vector in ascending order
        // Then, start from the cheapest bar and decrease the coins by the cost of the bar
        // If the coins are less than the cost of the bar, then break the loop
        sort(costs.begin(), costs.end());
        int bars = 0;
        for(auto& i : costs){
            if(i <= coins) bars++, coins -= i;
            else break;
        }
        return bars;
    }
};