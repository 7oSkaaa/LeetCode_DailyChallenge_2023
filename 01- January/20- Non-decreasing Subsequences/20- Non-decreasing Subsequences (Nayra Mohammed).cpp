//Author: Nayra Mohammed

#define sz(s) (int (s.size()))

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>>ans; // to store our final answer 
        set<vector<int>>s; // to store our answer as distict collections
        vector<int>curr; // to store our current subsequence
        
 /*
 nums's subsequences can be simulated as a binary representation (0_bit means don't take current element),( 1_bit means take current element) in ur  current subsequence
 so all we need is to find the max value to mask  our nums , which equals to  2 raised to the power( sz(nums) ) - 1
 
 for example : if our nums has 3 elements
 then all suitable masks are :
 binary -> decimal
 (000)2 -> (0)10
 (001)2 -> (1)10
 (010)2 -> (2)10
 (011)2 -> (3)10
 (100)2 -> (4)10
 (101)2 -> (5)10
 (110)2 -> (6)10
 (111)2 -> (7)10
 
(1000)2 -> (8)10 (isn't suitable as the forth bit will mask nothing so no need to go further!!)
 
 
 */
        for(int i = 0 ; i < (1<<sz(nums));i++) //use all suitable masks
        {
            curr.clear();  // for each mask we clear our current to generate the new subsequence in it  
           
            bool bad = 0; // to know whether current subsequence is valid or not
          
            for(int j = 0 ;j < sz(nums)&& !bad;j++) //iterate through nums'elements and apply the mask over it
              
                if( i & (1 << j)) // if current bit is 1 the we take current element
                {
                    bad |= (sz(curr) > 0 && nums[j] < curr.back()); //check whether current element is unvalid (prevents the subsequence to become non decreasing)
                    curr.push_back(nums[j]); // push current subsequence
                }

            if(!bad && sz(curr) > 1 ) s.insert(curr);  //if our subsequence is non decreasing and has size from [2...sz(nums)] then it's valid and we add it
        }

        for(auto it:s) //for each subsequence we stored in set  we push it to our final destination.
          ans.push_back(it);
      
        return ans;
    }
};
