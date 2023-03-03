// Author: Osama Ayman
class Solution {
    public int strStr(String haystack, String needle) {
        // try all indexes and return the first index that match
        for(int i=0; i<haystack.length()-needle.length()+1; i++){
            if(check(haystack, needle, i)) return i;
        }
        return -1;
    }
    private boolean check(String h, String n, int strt){
        int idx=0;
        for(int i=strt; i<n.length()+strt; i++){
            if(h.charAt(i)!=n.charAt(idx++)) return false;
        }
        return true;
    }
}