// Author: Osama Ayman
class Solution {
    public int minimumRounds(int[] tasks) {
        // count the fequency of each number
        HashMap<Integer, Integer> freq = new HashMap<>();
        for(int x: tasks){
            freq.put(x, freq.getOrDefault(x,0)+1);
        }
        int res = 0;
        for(int x: freq.keySet()){
            int val = freq.get(x);
            // if freq = 1, we cant do anything
            if(val==1){
                return -1;
            }
            // calculate remainder when freq divided by 3. 
            // The reason we chose 3 beacuse we want to get the minumum number of rounds.      
            // So, if a number is divisible by 2 and 3 we should consider 3 not 2.
            int rem = val%3;

            // if divisble by 3, just add freq/3.
            if(rem==0) res+= val/3;
            // if rem is 2, use 1 round of size 2, then the rest is divisble by 3.
            else if (rem==2) res+= (val-2)/3 + 1;

            // if rem is 1, then use 2 rounds of size 2, then the rest is divisble by 3.
            else res+= (val-4)/3 + 2;
        }
        return res;
    }
}