// Author: Osama Ayman
// Time: O(n)
// Space: O(1)
class Solution {
    public int compress(char[] chars) {
        // idx will save where we will to write in the chars array
        int idx=0;
       for(int i=0; i<chars.length; i++){
           int j=i+1, cnt=1;
           // count the number of occurence of chars[i]
           while(j<chars.length && chars[j]==chars[i]){
               cnt++;
               j++;
           }
           // write the cur char & increment idx
           chars[idx++]=chars[i];

           if(cnt>1 ){
               // convert the count from int to string
               String s = String.valueOf(cnt);
               // write in the chars array char by char
               for(char c: s.toCharArray()){
                   chars[idx++]=c;
               }
               
           }
           // update the i to point to the next new char
           i=j-1;
       }
       return idx;
    }
}