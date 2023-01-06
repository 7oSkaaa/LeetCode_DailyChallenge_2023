// Author: Nayra Mohammmed

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;// here we store the overall frequencies for tasks
      
        int mn_rounds = 0;//the overall ans
     
        for(auto it:tasks)mp[it]++;//for each task increase its frequency
        
        for(auto el:mp){

            //the minimum frequency that we can handle for rounds is 2,otherwise the answer = -1
            if(el.second == 1)return -1;
            
            /*needing to get the minimum rounds as possible for each task
              we can think of it as the following equation;
              3*x + 2*y = task's frequency such in it we have 3s as much as possible
              the maximum possible 3s we can have is (task's frequency/3)
            */
            mn_rounds+=(el.second/3);
            
            /*
            in case our task's frequency is divisable by 3, we add nothing
            
            in case it % 3 == 1,we need to take one of 3s and merge it
            into that 1, making 4 to be divisible by 2 (increase rounds by 1) 

            in case it % 3 == 2,then increase rounds by 1  
            */
            
            mn_rounds+=(el.second % 3 !=0);


        }
        
        return mn_rounds;
    }
};
