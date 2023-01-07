//Author: Anas Maher

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totG=0; for(int i=0 ; i<gas.size(); i++) totG+=gas[i];
        int totC=0; for(int i=0 ; i<cost.size(); i++) totC+=cost[i];

        if(totG<totC)return -1; // if total gas is less than total cost then its not possible to complete the route.

        int ans=0, cur=0; // starting position, current gas.
        for(int i=0 ; i<gas.size() ; i++)
        {
            cur += gas[i] - cost[i]; // update current gas.
            if(cur < 0) 
            {
                cur=0;
                ans = i+1;
            }// if current gas less than zero, then not valid position, try next position.
        }
        return ans;
    }
};
