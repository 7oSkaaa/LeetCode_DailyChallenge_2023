// Author: Osama Ayman
// Time: O(word1.length + word2.length)
// Space: O(1) not counting the output string
class Solution {
    public String mergeAlternately(String word1, String word2) {
        // string result
        StringBuilder sb = new StringBuilder();
        // index for word1 and index for word2
        int i1 = 0, i2 = 0;
        // boolean to alternate between words
        boolean one = true;
        while(i1<word1.length() && i2<word2.length()){
            if(one) {
                sb.append(word1.charAt(i1++));
            }
            else{
                sb.append(word2.charAt(i2++));
            }
            // negate the boolean to take from the other word next iteration
            one = !one;
        }
        // now only 1 word is not consumed
        while(i1<word1.length()){
            sb.append(word1.charAt(i1++));
        }
        while(i2<word2.length()){
            sb.append(word2.charAt(i2++));
        }
        return sb.toString();
    }
}