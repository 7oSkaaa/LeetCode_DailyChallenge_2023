// Author: Mohamed Amr
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // count the number of icecreams
        int count = 0;
        // sort the array to get the cheapest icecreams first.
        sort(costs.begin(), costs.end());
        int i=0;
        // check for coins-costs[i] to avoid reaching a negative value of icecreams
        while(i<costs.size() && coins-costs[i]>=0)
        {
            count++;
            coins -= costs[i++];
        }
        return count;

    }
};