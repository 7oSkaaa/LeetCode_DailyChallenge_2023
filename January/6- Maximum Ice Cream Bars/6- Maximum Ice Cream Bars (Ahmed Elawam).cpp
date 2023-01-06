//author: Ahmed Elawam
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt =0;

        for (auto e : costs){
            if (e<=coins){
                coins-=e;
                cnt++;
            }
        }
        return cnt;

    }
};