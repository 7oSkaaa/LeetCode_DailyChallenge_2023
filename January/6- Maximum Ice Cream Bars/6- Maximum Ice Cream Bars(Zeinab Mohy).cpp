// Author: Zeinab Mohy

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //sort costs from smaller to bigger
        sort(costs.begin(),costs.end());
        int sum=0,c=0;
        for(int i=0;i<costs.size();i++){
            /*check by count all costs if it less or equal coins
                if it is then sum the cost and count number of 
                icecream if not then break loop
            */
            if(costs[i]+sum<=coins){
                sum+=costs[i];
                c++;
            }else{
                break;
            }
        }
        //return the number of icecream which he can buy 
        return c;
    }
};
