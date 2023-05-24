// Author: Osama Ayman
// Time: O(n) 
// Space: O(n)
class Solution {
    public long mostPoints(int[][] questions) {
        return solve(questions, 0);
    }
    Map<Integer, Long> memo = new HashMap<>();
    private long solve(int[][] questions, int idx){
        // base case, out of bounds
        if(idx >= questions.length) return 0;
        // if already saved, return it
        if(memo.containsKey(idx)) return memo.get(idx);
        // solve
        long sol = questions[idx][0] + solve(questions, idx + 1 + questions[idx][1]);
        // skip
        long skip = solve(questions, idx+1);
        // result is the max of solve and skip
        long res = Math.max(sol, skip);
        // save result
        memo.put(idx, res);
        return res;
    }
}