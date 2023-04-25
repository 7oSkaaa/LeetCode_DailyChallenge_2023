// Author: Osama Ayman
// Time: O(n)
// Space: O(1) beacuse the number of chars in the set will never exceed 26;

class Solution {
    public int partitionString(String s) {
        int res=1;
        // maintain a set to save previously contained chars in the same partition
        Set<Character> set = new HashSet<>();
        for(char c: s.toCharArray()){
            if(set.contains(c)){
                // increment the res
                res++;
                // reset the set
                set = new HashSet<>();
            }
            // add it to cur set
            set.add(c);
        } 
        return res;
    }
}