// Author: Esraa Syam
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map < int , int > mp;
        int ans = 0;
        // get the frequency of each task
        for(auto & i : tasks) mp[i]++;
        // if there is a task that has frequency 1 then return -1
        for(auto & [f ,s] : mp){
            if(s == 1){
                ans = -1;
                break;
            }
        }
        if(ans == -1) return ans;
        // to get the minimum number of rounds we need to divide each task by 3
        // and if the remainder is not 0 then we need to add 1 to the answer
        // because if the remainder is 1  we need 2 round to complete the 4 tasks (2 , 2) instead of (3 , 1)
        // and if the remainder is 2 we need 1 round 
        // and if the frequency of a task is 0 then we don't need to do anything
        for(auto & [f , s] : mp){
            if(s == 0) continue;
            ans += s / 3 , s %= 3;
            if(s) ans++;
        }
        return ans;
    }

};