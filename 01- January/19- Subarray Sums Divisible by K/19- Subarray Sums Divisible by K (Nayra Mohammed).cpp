// Author : Nayra Mohammed

#define MemS(s, x) memset(s, x, sizeof(s))

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // ans ->  to store number of subarray's sum divisible by k
        // sum ->  to calculate current prefix sum under mod k
        // mp  ->  to store the frequancies of prefix sums under mod k
        int ans = 0, sum = 0, mp[k];
        MemS(mp,0);
        
        mp[0]++; //our basecase to get answer in case of current prefix subarray is divisible by k 
      
        for(auto it:nums){
            sum += it; //add current element
            sum = ((sum % k) + k)%k; //apply mod to sum  (keep in mind we may deal with negative value)
           
          /*
            Dealing with prefix suppose our k = 5 and the sum after applying mod for current prefix = 2
            let's remember modular arithmatic summation case, it's like (x+y+z...)%k  = ((x%k )+ (y%k) +(z%k) ...) %k
            So, Adding an element for current prefix is like sum = ((sum %k ) + (element %k )) %k
            
            From this point, if sum_mod is any value but 0 , then there was an addition operation where we added at least an element(having that value under mod)that caused the undivisibilty
            so we can say for any previous prefix having same sum_mod as current prefix then deleting them will get us a subarray'sum divisible by k
            */
          
            ans += mp[sum]; //add the frequency of that value    
            mp[sum]++;   //increment current prefix_sum's mod 
        }
      
        return ans; 
    }
};
