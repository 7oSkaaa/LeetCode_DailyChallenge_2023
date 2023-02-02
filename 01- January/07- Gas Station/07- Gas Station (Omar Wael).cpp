// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
        }
        // if the total amount of cost is greater than total amount of gas return -1
        if(total<0){
            return -1;
        }
        int sum=0;
        int ans=-1;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
            // if the gas greater than cost and you did not pick station then pick this one
            if(sum>=0 && ans==-1){
                ans=i;
            }// if the total amount of cost is greater than total amount of gas then leave the picked station
            else if(sum<0){
                sum=0;
                ans=-1;
            }
        }
        return ans;
    }
};