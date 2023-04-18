// Author: Osama Ayman
// Time: O(n)
// Sapce: O(1) (not counting size of output)
class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int n = candies.length;
        
        List<Boolean> res = new ArrayList<>();
        // finding the max
        int max = candies[0];
        for(int i=1; i<n; i++){
            max = Math.max(max, candies[i]);
        }
        for(int i=0; i<n; i++){
            // if giving the extra cndies to cur kid will make him the greatest one with number 
            // of candies, add to true to the result
            if(candies[i]+extraCandies >= max){
                res.add(true);
            }
            // else add false
            else res.add(false);
        }

        return res;
    }
}