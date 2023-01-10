// Author: Anas Maher

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end()); // taking cheapest ones first means taking more.
        
        int res=0, n=costs.size(), i=0; 
        while(i<n && coins>=costs[i]) {res++; coins-=costs[i]; i++;}
        /* 
           if current coins >= the cost of the next cheapest icecream, buy it, remove its cost from current coins, 
           else if current coins are less than next icecream : cant buy anymore as the next one is the cheapest,
           return number of icecreams bought.
        */
        return res;
    }
};

