// author: Esraa Syam
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // zeros is the number of zeros we have to flip to make the string monotonically increasing
        // ones is the number of ones we have to flip to make the string monotonically increasing
        int zeros = 0 , ones = 0; 
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '1') ones++;  // if we find a one we increment ones  
            else{
                // if we find a zero we increment zeros and we take the minimum between zeros and ones 
                // because we want the minimum number of flips to make the string monotonically increasing
                zeros++;
                zeros = min(zeros , ones);
            }
        }
        return zeros;
    }
};
