// Author : Eman Elsayed

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        // first sort costs of ice creams in ascending order.
        sort(costs.begin(), costs.end());
        // counter and sum of ice creams prices.
        int cnt = 0, sum = 0;
        // iterate through ice creams, if cost of each is affordable just buy it :)
        for (int i = 0; i < costs.size(); i++)
        {
            sum += costs[i];
            // if sum of ice creams prices is greater than coins, break.
            if (sum > coins)
                break;
            // else increase count of bought ice creams by 1.
            cnt++;
        }
        // return count of bought ice creams.
        return cnt;
    }
};