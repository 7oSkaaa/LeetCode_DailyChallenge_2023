// Author: Osama Ayman
class Solution {
    public boolean isScramble(String s1, String s2) {
        return solve(s1, s2);
    }
    // map to save computed results.
    Map<String, Boolean> mem = new HashMap<>();
    private boolean solve(String s1, String s2){
         int n = s1.length();
        // must have same length
        if(n!=s2.length()) return false;
        if(s1.equals(s2)) return true;

        String key = s1+","+s2;
        if(mem.containsKey(key)) return mem.get(key);
       
        // try all possible partitions (n-1)
        for(int i=1; i<s1.length(); i++){
            // try keeping the order of the string and swapping.
            if(solve(s1.substring(0,i), s2.substring(0,i)) && solve(s1.substring(i), s2.substring(i))
            || solve(s1.substring(0,i), s2.substring(n-i)) && solve(s1.substring(i), s2.substring(0,n-i)) )
            // save result
            {mem.put(key, true); return true;}
        }
        mem.put(key, false);
        return false;
    }
}