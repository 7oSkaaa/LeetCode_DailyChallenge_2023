//Author: Reham Atta

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        long long sum=0;
        int cnt=0,n=costs.size();
        sort(costs.begin(),costs.end());
        for(int i=0;i<n;i++) {
            if(costs[i] <= coins && sum < coins) {
                sum+=costs[i];
                cnt++;
                // after add the costs[i] to sum suppose sum became greater than coins then we subtract the last value we added to sum costs[i]
                if(sum > coins) { 
                    cnt--; 
                    break;
                }
            }
        }
        return cnt;
    }
};