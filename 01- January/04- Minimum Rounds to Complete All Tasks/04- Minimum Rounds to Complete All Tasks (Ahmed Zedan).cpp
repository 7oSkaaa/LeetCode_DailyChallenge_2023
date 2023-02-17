// author : ahmed zedan
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int , int > freq ;  
        for(auto &i : tasks) freq[i]++ ;   // count frequance of tasks  
        int ans = 0 ;                            
        for(auto &[f,s] : freq){
            if(s==1) return -1 ;           // can do 2 or 3 tasks of the same task so task exit only once can't do it
            else ans += (s/3)+(s%3!=0) ;  
            //need to get minimum rounds required to complete all the tasks
            // so if (freq[task]%3==0) do it in s/3 times
            // if (freq[task]%3==1||freq[task]%3==2) do it in (s/3)+1 times 
            // why ?? 
            // ex : freq[task]=7 (7%3==1)
            // floor(7/3)=2 so 7 = 3 + 3 + 1 if merge 3 + 1 = 4 (4%2==0) -> 7 = 3 + 2 + 2  
            // ex : freq[task]=8 (8%3==2)
            // floor(8/3)=2 so 8 = 3 + 3 + 2 
            // that mean we can do tasks only if freq[task]>1    
        }
        return ans ; 
    }
};