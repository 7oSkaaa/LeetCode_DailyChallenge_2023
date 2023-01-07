// Author: Mohamed Tolba

class Solution {
  int maxIceCream(List<int> costs, int coins) {
    int mx = 0;
    // sort costs in increasing order
    costs.sort();
    for (int i = 0; i < costs.length; i++) {
      if (costs[i] > coins) break;
      // reduce price of picked ice creams from our coins
      coins -= costs[i];
      mx++;
    }
    return mx;
  }
}
