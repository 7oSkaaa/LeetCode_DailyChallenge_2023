//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //tot: comparing the overall gases'sum with costs'sum
        //ans: our starting station answer , initialize it with the first station
        //curr: to trace whether we can continue with that starting point or not
        int curr = 0,tot = 0,ans = 0;

        for(int i = 0;i < sz(gas); i++)
        {
            curr += (gas[i] - cost[i]);
            tot += (gas[i] - cost[i]);
            
            if(curr < 0) /* in that case we reached a bad station i,so we change our starting point to i+1 not to ans + 1. 
              having a bad station means any good station start before it will result to the same bad station*/
                ans = i + 1, curr = 0;
        }

        return (tot < 0 ? -1 : ans);//if overall gases'sum is less than costs'sum then no station is valid,otherwise print the answer
    }
};
