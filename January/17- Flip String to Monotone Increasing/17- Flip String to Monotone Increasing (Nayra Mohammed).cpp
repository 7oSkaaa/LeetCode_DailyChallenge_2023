//Author : Nayra Mohammed

#define sz(s) (int(s.size()))
/*
valid strings after operation are:
11111
01111
00111
00011
00001
00000
so we can see a continuous part of zeros(maybe 0)  followed by ones
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
          
         // z to count the prefix count of zeros
         // o to cound the suffix count of ones
         // ans to store the minimum answer as  possible (initially with maximum value = size of string s itself)  
        int z = 0, o = 0, ans = sz(s);
        
        for(auto it:s)
            o += (it -'0');// count all ones we have (keep in mind we treat it as a suffix not a prefix)
        
        ans = min(ans, sz(s) - (o + z)); // for each new zero's prefix and one's suffix we update our answer 
      
        /* sz(s) - (o + z) means the reminder uncontained characters in our (zero's prefix and one's suffix) 
           for example : 01011111
           current z = 0 , o = 6
           then to make it 11111111 we need to flip the two zeros ( 8 - (0 + 6) ) = 2
           
           and to make it 01111111 .
           current z = 1 , o = 6 ,we need to flip one zero (8 - ( 1 + 6)) = 1 
           
           and, so on..
        */
      
        for(auto it:s)
        {
            z += ( it == '0'); //update our zero's prefix
            o -= (it - '0');  // update our one's suffix
            ans = min(ans, sz(s) - (o + z)); //minimize the answer to get the required request
        }
      
        return ans; 
    }   
};
