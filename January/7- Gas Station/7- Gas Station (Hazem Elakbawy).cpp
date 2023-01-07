// Author : Hazem Elakbawy
class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    /*
    Approach :-
      as there is (unique path) through stations or (no such path exits)
      **  if (cost of all gases) > (total gases) ==> no such route exists
      **  else :-
      ##  we can check on each station if our total gas is enough or not
      --> if negative : then its not the path & update startpoint to next station
      --> else        : then continue checking on next stations
    */
    int n = cost.size();
    int res = 0, diff = 0, costs = 0, gases = 0;
    for (int i = 0; i < n; i++)
    {
      costs += cost[i];
      gases += gas[i];
      diff += (gas[i] - cost[i]);
      if (diff >= 0)
        continue;
      diff = 0;
      res = i + 1;
    }
    costs > gases ? res = -1 : res;
    return res;
  }
};