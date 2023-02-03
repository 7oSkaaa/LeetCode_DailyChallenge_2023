// Author: Mohamed Tolba

class Solution {
  int canCompleteCircuit(List<int> gas, List<int> cost) {
    int position = 0, tank = 0, start = 0;

    for (int i = 0; i < gas.length; i++) {
      tank += gas[i] - cost[i];

      // Add the difference between gas and cost at each station to position
      position = position + (gas[i] - cost[i]);

      // If position becomes negative, set start to the next station and reset position
      if (position < 0) {
        start = i + 1;
        position = 0;
      }
    }

    return (tank < 0) ? -1 : start;
  }
}
