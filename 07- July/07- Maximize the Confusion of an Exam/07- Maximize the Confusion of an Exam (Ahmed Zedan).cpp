// author : Ahmed Zedan
class Solution {
public:
    // sliding window approach
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size() , l = 0 , r = 0 , ans = 0 ; 
        int t = 0 , f = 0 ; 

        while(r<n){
            // move r pointer 
            (answerKey[r++]=='T'?t++:f++);

            // if (l t0 r) valid subarray update answer 
            if(t<=k||f<=k) ans = max(ans , r-l) ;

            // if (l to r) invalid subarray move l pointer  
            if(t>k && f>k) (answerKey[l++]=='T'?t--:f--); 
        }

        return ans ; 
    }
};