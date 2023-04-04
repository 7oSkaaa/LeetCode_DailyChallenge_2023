// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // sort people weights
        sort(people.begin(),people.end());
        int ans=0;
        // the idea is to get biggest person and smallest one
        // if the sum of them less than or equal the limit
        // carry both of them
        // if not carry the biggest one 
        int l=0,r=people.size()-1;
        while(l<=r){
            if(people[l]+people[r]<=limit){
                ans++;
                l++;
                r--;
            }else {
                ans++;
                r--;
            }
        }
        return ans;
    }
};
