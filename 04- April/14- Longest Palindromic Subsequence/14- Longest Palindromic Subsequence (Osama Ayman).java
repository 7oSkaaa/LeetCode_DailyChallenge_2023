// Author: Osama Ayman
// Time: O(n^2)
// Space: O(n^2)
class Solution {
    // map to save calculated results
    Map<String, Integer> hm = new HashMap<>();
    public int longestPalindromeSubseq(String s) {
        
        return solve(s, 0, s.length()-1);
    }
    
    private int solve(String s, int strt, int end){
        String key = strt+","+end;

        if(hm.containsKey(key)) return hm.get(key);
        // if they cross, then the search is over
        if(strt > end) return 0;
        if(strt == end) return 1;
       
    // if char of strt == char of end, return 2 + solve(strt+1, end-1)
        if(s.charAt(strt)==s.charAt(end)){
            int res = 2 + solve(s, strt+1, end-1);
            hm.put(key, res);
            return res;
        }

    //else, try both moving the strt alone and moving the end alone
        int res = Math.max(solve(s, strt+1, end), solve(s, strt, end-1));
        hm.put(key, res);
        return res;
    }
}