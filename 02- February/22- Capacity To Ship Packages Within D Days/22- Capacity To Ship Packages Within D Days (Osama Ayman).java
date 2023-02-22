// Author: Osama Ayman
class Solution {
    public int shipWithinDays(int[] weights, int days) {
        // binary search on the result
        int hi = 25_000_000, lo=1, mid, res=hi;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            // if it is possible then save this result adn try to find another minimum 
            // solution
            if(isPossible(mid, days, weights)){
                res = mid;
                hi=mid-1;
            }
            // if its not possible, then we must increase the capacity
            else{
                lo=mid+1;
            }
        }
        return res;
    }
    private boolean isPossible(int maxWeight, int days, int[] w){
        int daycnt=1;
        int sum=0;
        for(int i=0; i<w.length; i++){
            // if the cur number is larger than the max capacity, then its impossible 
            // to take it
            if(w[i] > maxWeight ) return false;
            // if we added the cur number to the sum and its is still less than or 
            // equal to max weight, then take it
            if(sum+w[i] <= maxWeight) sum+=w[i];
            // if its not possible to add it, then we need another day
            else {
                daycnt++;
                // if the day count exceeds the given days, its a wrong solution
                if(daycnt > days) return false;
                sum = w[i];
            }
        }
        return true;
    }
}