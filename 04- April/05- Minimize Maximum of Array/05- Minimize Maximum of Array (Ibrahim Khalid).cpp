// Author: Ibrahim Khalid
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int sz=nums.size();

        // store first value because the result won't less it

        int res=nums[0];

        int f;

        double sum=nums[0];
        //We want to distribute the numbers equal from left to right
        //and compare them with the first and take max by collecting them and dividing them by their number
        for(int i=1;i<sz;i++){

            sum+=nums[i];

            f=ceil(sum/(i+1));
            
            res=max(res,f);
        }
        return res;
    }
};
