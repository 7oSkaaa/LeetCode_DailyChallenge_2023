// Author: Mazen Alasas

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Sort vector
        sort(costs.begin(), costs.end()); 

        int answer = 0, sum = 0;
        // If the coins were not enough
        if (costs[0] > coins) 
            return 0;
        // And if
        for (int i = 0; i < costs.size(); i++) {
            // Ialculate the price of ice cream bars
            sum += costs[i];
            
            // If coins are no longer enough break the loop
            if (sum > coins)
                break;
            else // If not then can buy more
                answer++;
        }
        // And this is the maximum number of ice cream bars the boy can buy with coins
        return answer;
    }
};
