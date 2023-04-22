// Author: Osama Ayman
// Time & Sapce: O(s.length^2)
class Solution {
    public int minInsertions(String s) {
        return solve(s, 0, s.length()-1);
    }
    // map to save results to avoid recalculations
    Map<String, Integer> hm = new HashMap<>();
    private int solve(String s, int lo, int hi){
        if(lo >= hi) return 0;
        String key = lo+","+hi;
        if(hm.containsKey(key)) return hm.get(key);
        // if there is a match, move low and high
        if(s.charAt(lo) == s.charAt(hi)){
            // no insertion needed
            return solve(s, lo+1, hi-1);
        }
        // else try both adding to the left and adding to the right
        int left = 1+solve(s, lo, hi-1);
        int right = 1+solve(s, lo+1, hi);
        // result is the min of left & right
        int res = Math.min(left, right);
        // save the result
        hm.put(key, res);
        return res;
    }
}