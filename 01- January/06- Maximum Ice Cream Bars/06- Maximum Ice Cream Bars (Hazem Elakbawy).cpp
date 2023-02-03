// Author : Hazem Elakbawy
class Solution
{
public:
  int maxIceCream(vector<int> &costs, int coins)
  {
    int n = costs.size();
    // sorts the costs vector ascending to count smaller bar costs first
    sort(costs.begin(), costs.end());
    for (int i = 0; i < n; i++)
    {
      if (coins < costs[i]) // no enough coins for further bars
        return i;
      coins -= costs[i]; // subtract each bar value from current coins
    }
    return n; // if all bar costs are affordable then return vector size
  }
};
