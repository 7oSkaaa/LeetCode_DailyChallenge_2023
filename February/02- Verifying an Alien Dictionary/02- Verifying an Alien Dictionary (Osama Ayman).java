// Author: Osama Ayman
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        // saving the order of each character
        int[] ar = new int[26];
        int num=1;
        for(char c: order.toCharArray()){
            ar[c-'a'] = num++;
        }
        for(int i=1; i<words.length; i++){
            if(!sorted(words[i-1], words[i], ar)){
                return false;
            }
        }
        return true;
    }
    private boolean sorted(String s1, String s2, int[] ar){
        int min = Math.min(s1.length(), s2.length());
        for(int i=0; i<min; i++){
            // if the first char that differ is smaller in s1, return true
            if(ar[s1.charAt(i)-'a'] < ar[s2.charAt(i)-'a']){
                return true;
            }
            // if the first char that differ is smaller in s2, return false
            else if(ar[s1.charAt(i)-'a'] > ar[s2.charAt(i)-'a']){
                return false;
            }
            // if they're equal compare the next chars.
        }

        // if all char are equal, then the length of s1 must be smaller than or equal to that 
        // of s2
        return s1.length() <= s2.length();

    }
}