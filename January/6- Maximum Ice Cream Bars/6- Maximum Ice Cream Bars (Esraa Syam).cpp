// author: Esraa Syam
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        int cost = 0 , i = 0;
        for(i = 0 ; i < costs.size() ; i++){
            // if the cost is greater than the coins  return the number of icecreams (i - 1 + 1) = i (i - 1 is the index of the last icecream that can be bought) + 1 (beacuse the index starts from 0)
            cost += costs[i];
            if(cost > coins) break;
        }
        return i;
    }
};