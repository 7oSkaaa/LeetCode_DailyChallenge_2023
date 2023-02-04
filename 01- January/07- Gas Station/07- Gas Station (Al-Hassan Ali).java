// Author : Al-Hassan Ali

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int sum_gas = get_sum(gas);
        int sum_cost = get_sum(cost);
        // Get Sum of Gas we add and the sum of the gas we lost during journey if the sum of the gas we lost is greater than gas we add so it's 
        // Definitly We Cannot make a Complete Journey
        if(sum_cost > sum_gas)
            return -1;
        
        // Loop to get the result 
        int cur_sum = 0, idx = -1;
        for(int i = 0; i < gas.length; i++) {
            // It means it's a new beginning of a slot of numbers
            if(cur_sum == 0) idx = i;
            int current_gas = gas[i] - cost[i]; 
            cur_sum += current_gas;
            
            // Last Slot wasn't valid
            if(cur_sum < 0) {
                cur_sum = 0;
                idx = -1;
            }
        }
        return idx;
    }
    // Get Sum of the elemntes in the array
    static int get_sum(int []arr) {
        int sum = 0;
        for(int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        return sum;
    }
}

/*
    Time Complexity : O(n)
    Memory Complexity : O(1)
*/