// Author: Osama Ayman
class Solution {
    public int maxProfit(int[] prices) {
        // keep track of the min number (buy value) and when there is a bigger val try 
        // sell it & when there is min val update buy.
        int profit=0;
        int buy = Integer.MAX_VALUE;
        for(int x: prices){
            if(x < buy) buy=x;
            else{
                profit=Math.max(profit, x-buy);
            }
        }
        return profit;
    }
}