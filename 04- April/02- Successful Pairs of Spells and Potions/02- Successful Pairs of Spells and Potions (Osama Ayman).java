// Author: Osama Ayman
// Time: O(n*log(m))
// Space: O(1) -> not counting the output array
class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length, m = potions.length;
        int[] output = new int[n];
        // sorting the array to make it easier to find result by binary search
        Arrays.sort(potions);
        long multiply;
        for(int i=0; i<n; i++){
            int lo=0, hi=m-1, res = m;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                // cur multiplication result
                multiply=spells[i]*(long)potions[mid];
                // if multiply is smaller than success, then its not valid, increase lower
                if(multiply < success) lo=mid+1;
                else{
                    res = mid;
                    // find a lower index
                    hi=mid-1;
                }
            }
            output[i] = m-res;
        }
        return output;
    }
}