// Author: Osama Ayman
// Time: O(n)
// Space: O(1)
class Solution {
    public int maxVowels(String s, int k) {
        // vowels cnt
        int cnt = 0;
        // Sliding Window
        int left = 0;
        int max = 0;
        for(int i=0; i<s.length(); i++){
            
            while(i-left+1 > k){
                char tail = s.charAt(left);
                // if char at tail is vowel decrease the count of vowels
                if(tail=='a' || tail=='e' || tail=='i' || tail=='o' || tail=='u'){
                    cnt--;
                }
                // decrease the size of the window
                left++;
            }
            // if cur char is vowel, increase the cnt of the vowel
            char cur = s.charAt(i);
            if(cur=='a' || cur=='e' || cur=='i' || cur=='o' || cur=='u') cnt++;
            // update max count
            max = Math.max(max, cnt);

        }
        return max;
    }
}