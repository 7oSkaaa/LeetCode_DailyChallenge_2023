// Author : Nayra Mohammed

#define sz(s) (int(s.size()))
/*
  - to find a string t divided s "i.e s = t + t + t + t + ..... + t" we need to check for every prefix string of s (s0 + s1 + s2 + s3 + .... )
  - Here we need to find the GCD between 2 strings s1 and s2  "the longest string t that divides both s1 and s2"
  - Our range of sizes to construct t would be [0,min(s1.size() , s2.size())], if we try a bigger range will just be a waste of time. 
    As if t have a bigger size than E.g. s1 then for sure  s1 != t .
  - So for every valid range prefix we need to check if s1 and s2 are divisible by it !
*/
class Solution {
public:
    
    bool  Check_Similarity (string &x, string &GCD){
        
        if(sz(x) % sz(GCD)) // if our string's size isn't divisable by the prefix's size "the GCD won't be able to make a valid identical string to the original string"
            return 0;
        
        int id = 0; // consider it as our pointer for current character in GCD
        bool bad = 0; // to know whether the GCD string can divides x or not 
        
        for(int i = 0; i < sz(x) ; i++) //iterate over string's character and check if current character is identical to the faced charcater in GCD's
            bad |= (x[i] != GCD [id % sz(GCD)]), id++; // id++ to go to the next character in the GCD for the upcomping character of x
                                                       // instead of checking whether id reached the end of GCD or not to start all over again
                                                       // we can take the mod between id and GCD's size to know which character we re currently pointing to
                                                      
        return !bad ;  // if our boolean is still unchecked then GCD divides string x !  
    }

    string gcdOfStrings(string str1, string str2) {
        // ans --> store GCD(str1,str2) (aka. the longest string that divides both str1 and str2 )
        // pre --> store current generated prefix in our pre_specified ranges! 
        string ans = "",pre = "";

        for (int i = 0 ; i < min(sz(str1),sz(str2)); i++)
        {
            pre += str1[i]; //add current character at the end of previous prefix  (better than using "substr" function)
            
            if(Check_Similarity(str1,pre) && Check_Similarity(str2,pre))  // if both strings are divisable by current prefix then we consider it as our current answer
                ans = pre;   
        }  

        return ans; 
    }
};
