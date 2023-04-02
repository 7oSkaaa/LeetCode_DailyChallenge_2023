// Author: Osama Ayman
// Time: O(n^2)
// Space: O(n^2)
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        // sort so dishes with high satisfaction comes at the end, 
        // so it can be mulitiplied by a bigger factor.
        Arrays.sort(satisfaction);
        return solve(satisfaction, 0, 1);
    }
    Map<String, Integer> dp = new HashMap<>();
    private int solve(int[] s, int idx, int cnt){
        if(idx==s.length) return 0;
        // if already calculated, return the saved result
        if(dp.containsKey(idx+","+cnt)) return dp.get(idx+","+cnt);
        // Do this dish
        int doDish = s[idx]*cnt + solve(s, idx+1, cnt+1);
        // Skip this dish
        int skipDish = solve(s, idx+1, cnt);
        int res = Math.max(doDish, skipDish);
        // save the result
        dp.put(idx+","+cnt, res);
        return res;
    }
}