// Author : Omar Waael

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        map<int,int>mp;
        //count the frequency of each level
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            // if the number of frequency is multiple of 3 then all ronds will complete 3 tasks
            if(it.second%3==0){
                ans+=it.second/3;
            }// if the reminder equal 2 then all ronds will complete 3 tasks except last one (will complete 2 tasks)
            else if(it.second%3==2){
                ans+=it.second/3;
                ans+=1;
            }// if the reminder equal 1 and number of frequency greater than 1 then all ronds will complete 3 tasks except last two (will complete 2 tasks)
            else if(it.second>1){
                ans+=it.second/3;
                ans+=1;
            }// if the number of frequency equal 1 return -1
            else{
                return -1;
            }
        }
        return ans;
    }
};