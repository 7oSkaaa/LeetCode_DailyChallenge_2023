//Author : Omar Salem
class Solution {
public:
    int jump(vector<int>& nums) {
    // initialize varibals     
       int ans = 0, MaxPoint = 0 , EndPoint = 0;
       for(int i = 0 ; i < nums.size() - 1; i++)
       {
           // taka Max point can you reach it
           MaxPoint = max(MaxPoint  ,i + nums[i]);
           if(i == EndPoint)
           {
            // inc num of jump
               ans++;
            //  change end point to point you reach it 
               EndPoint = MaxPoint;
           }
       }
       // return answer
       return ans;
    }
};