// Author: Mohamed Amr
// Topic: implementation
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int>temp(n);
        int sum = 0;
        // create a temp vector containing the difference between gas and cost;
        for(int i=0; i<n; i++)
        {
            temp[i] = gas[i] - cost[i];
            sum += temp[i];
        }
        int indx = 0;
        int t = 0;
        // compute the running sum starting from the beginning
        // everytime check if the running sum (t) is greater than temp[i];
        // if temp[i] is greater than t, then it is a better place to start from.
        for(int i=0; i<n; i++)
        {
            t += temp[i];
            if(temp[i] > t)
            {
                t = temp[i];
                indx = i;
            }
        }
        if(sum>=0)
            return indx;
        return -1;
    }
};