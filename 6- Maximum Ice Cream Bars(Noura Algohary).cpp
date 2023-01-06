class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt = 0; 

        sort(costs.begin(), costs.end());

        for(int i=0; i<costs.size();i++)
        {
            // if the coins is more than the current elemet cost, increment the counter(cnt) by one, 
            // and subtrat the cost from coins
            if(coins >= costs[i])
            {
                cnt++;
                coins -= costs[i];
            }
            //if he can't afford the current element, then he can't the rest of the array as it's a sorted array
            else
            return cnt;
        }
        return cnt;
    }
};