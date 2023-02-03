// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0,sum=0,rem;
        int freq[k];
        memset(freq,0,sizeof(freq));
        freq[0]=1;
        for(int i=0;i<nums.size();i++){
            // add current element to the sum
            sum+=nums[i];
            // get the remainder of the sum / k
            rem=sum%k;
            // check if the remainder is negative 
            if(rem<0){
                rem+=k;
            }
            // update the number of subarrays
            ans+=freq[rem];
            // update number of frequancy
            freq[rem]++;
        }
        return ans;
    }
};