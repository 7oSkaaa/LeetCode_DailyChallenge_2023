//ِAuthor: Omar Salem 
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size() , ans =0 ;
        vector < int > pre(n) , rem;
        pre[0] = nums[0];
        // 4 9 9 7 4 5
        // get summation of all subarrays using prefix sum
        for(int i = 1; i < n ; i++)
            pre[i] = pre[i - 1] + nums[i];
        // 4 4 4 2 4 0 
        // If we find that the remainder of the division was previously present then (x * k) is added to it 
        // and add K and % k to negative number 
        for(int i = 0; i < pre.size() ; i++)
            rem.push_back((pre[i] % k + k) % k) ;

        //count subarrays that have a sum divisible by k  
        map < int , int > countSubArray = {{0,1}};
        for(auto &i : rem)
        {
            ans += countSubArray[i];
            countSubArray[i]++;
        }
        return ans ; 

    }
};