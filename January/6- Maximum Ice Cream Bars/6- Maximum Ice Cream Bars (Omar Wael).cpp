// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        // sort costs to buy cheapest n ice cream
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++){
            ans++;
            coins-=costs[i];
            if(coins==0){
                break;
            }else if(coins<0){
                // if coins less than 0 do not buy last ice cleam
                ans--;
                break;
            }

        }
        return ans;
    }
};