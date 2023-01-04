class Solution {
public:
    int minimumRounds(vector<int>& arr) {
        map<int,int>m;
        //count the frequency of each level
        for(auto it:arr){
            m[it]++;
        }
        int ans=0;
        for(auto it:m){
            // if the Frequency of any level equal 1 , it's not possible to complete all the tasks.
            if(it.second==1){
                return -1;
            }
            else{
                // if the number of frequency is multiple of 3 then all ronds will complete 3 tasks
                if(it.second%3==0){
                    ans+=it.second/3;
                }
                // if the reminder equal 1 or greater all ronds will complete 3 tasks except last two 
                else if(it.second%3 >= 1){
                    ans+=it.second/3 + 1;
                }
                // if the number of frequency is multiple of 2 then all ronds will complete 3 tasks
                else if(it.second%2==0){
                    ans+=it.second/2;
                }
            }
        }

        return ans;
    }
};