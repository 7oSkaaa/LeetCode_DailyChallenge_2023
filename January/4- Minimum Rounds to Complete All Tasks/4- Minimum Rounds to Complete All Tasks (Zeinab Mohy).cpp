// Author: Zeinab Mohy

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        //using map to count freq for each number
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int ans=0;
        for(auto it:mp){
            //if freq = 1 then it mean it is not allowed to count which not equal 2,3
            if(it.second==1){
                ans=0;
                break;
            }
            //first check if it visible to 3
            else if(it.second%3==0){
                ans+=(it.second/3);
                //if it visible to 2
            }else if(it.second%2==0){
                //add 1 to make it visible which mean it has number of 3 which we can consider one of them is 2
                if((it.second+1)%3==0){
                    ans+=((it.second+1)/3);
                //add 2 to make it visible which mean it has number of 3 which we can consider two of them is 2    
                }else if((it.second+2)%3==0){
                    ans+=((it.second+2)/3);
                //if there is no one of them allowed it must visible for 2
                }else{
                    ans+=(it.second/2);
                }
            }else {
                // if the freq not visible for 2, 3 then try to add 1 or 2 
                if((it.second+1)%3==0){
                    ans+=((it.second+1)/3);
                }else if((it.second+2)%3==0){
                    ans+=((it.second+2)/3);
                }else{
                    ans+=(it.second/2);
                }
            }
        }
        //if ans !=0 then it means we can complete all tasks
        if(ans!=0){
            return ans;
        //if ans ==0 then it means there is task we con't complete 
        }else{
            return -1;
        }
    }
};
