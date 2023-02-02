//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        // we need to sort costs to get minimum values as much as we can
        sort(costs.begin(),costs.end());

        for(int i=0;i<sz(costs);i++){

            if(coins - costs[i] >= 0) /*we can pay the current cost,then we take it and remove it's value from coins*/
                coins -= costs[i];
            else //otherwise return the previous step as the final answer as a one_based index (i-1) + 1 = i
                return i; 
        }
        
        return sz(costs);//we have taken all the icecream bars ^_^
    }
};
