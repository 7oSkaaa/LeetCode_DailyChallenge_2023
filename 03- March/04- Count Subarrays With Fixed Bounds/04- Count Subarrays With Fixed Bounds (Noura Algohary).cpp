// Author: Noura Algohary
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // left is the current valid index of the number
        // left_min is the number equals minK
        // rigt_max is the number equals maxK
        int left = -1, left_min = -1, right_max = -1;
        long long cnt = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= minK && nums[i] <= maxK)
            {
                if(nums[i] == minK) 
                    left_min = i;

                if(nums[i] == maxK) 
                    right_max = i;

                int x = min(left_min, right_max) - left;

                if(x > 0)
                    cnt += x;
            }
            else
            {
                left_min = -1;
                right_max = -1;
                left = i;
            }
            
            //  cout<<"num[i]: "<<nums[i]<<endl;
            // cout<<"cnt: "<<cnt<<endl;
        }

        return cnt;
    }
};