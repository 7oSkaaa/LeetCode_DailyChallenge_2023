// Author: Osama Ayman
class Solution {
    public int maxIceCream(int[] costs, int coins) {
        // As we want the maximum number we can but, we have to buy the cheapest ice creams first.
        // So, sort the array ascendingly.
        Arrays.sort(costs);
        int res=0;
        for(int i=0; i<costs.length; i++){
            // when the current cost is greater than our remaining coins, we cant buy any more.
            if(costs[i] > coins) break;
            coins -= costs[i];
            res++;
        }
        return res;
    }
}