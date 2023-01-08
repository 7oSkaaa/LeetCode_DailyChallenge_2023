// Author: Mahmoud Aboelsoud

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // get the length of our arrays
        int n = gas.size();
        // initialize a vector with double the size of n to restore the same array again in the back so that we have a circular array
        vector<int> diff(n * 2);

        // get the difference of adding the gas at each station and subtracting the cost ot travel to the next station
        for(int i = 0; i < n; i++)
            diff[i] = gas[i] - cost[i]; 

        // put the same values again in the back to make the array circular
        for(int i = n; i < n * 2; i++)
            diff[i] = diff[i % n];

        // initialize our start point and the total sum
        int l = 0, sum = 0;

        for(int i = 0; i < 2 * n; i++){
            // add the difference to total sum 
            sum += diff[i];


            // if our sum becomes negative that means we cannot make our starting position l so we start to move to the next postion and subtract the diff 
            // at l from our total sum, we do this as many times as we need to make the sum >= 0 again 
            while(sum < 0){
                sum -= diff[l++];
            }

            // if we reach  a point where at it our sum has n values and never become negative at them we then can say that our start pos is absolutely l
            if(i - l + 1 == n) return l;
        }

        // otherwise there is no answer
        return -1;
    }
};
