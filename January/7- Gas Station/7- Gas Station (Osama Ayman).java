// Author: Osama Ayman
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int[] net = new int[gas.length];
        int sum = 0;
        // calculate net gas
        for(int i=0; i<gas.length; i++){
            net[i] = gas[i]-cost[i];
            sum+=net[i];
        }
        // if sum of net array is -ve, then we cant make a cycle
        if(sum < 0) return -1;

    // Now there must be a solution to this problem. So, the idea here is to be greedy.
    // if running sum is negative, then we cant make it from the initial start index.
    // the next index to condiser is last index we reached+1, becasue it cant be anything before 
    // that, as we 
    // have summed all numbers from start index and got -ve here, then  of course when we try to 
    // sum after start index it will also be -ve because the number of positives would be lower.
    int total = 0, strt = 0;
       for(int i=0; i<net.length; i++){
          total += net[i];
          if(total < 0){
              total = 0;
              strt = i+1;
              }
       }
       return strt;
    }
}