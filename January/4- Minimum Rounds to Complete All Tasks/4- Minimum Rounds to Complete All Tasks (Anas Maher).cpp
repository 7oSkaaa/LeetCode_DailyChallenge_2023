// Author: Anas Maher

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        map<int,int>mp; // using a map to store frequencies of tasks, a map instead of a vector because input range is 10^9

        int n = tasks.size(); // instead of calling size() functioon every iteration, storing the size in a variable first saves some time.

        for(int i=0 ; i<n ; i++) mp[tasks[i]]++; // storing frequency of tasks.

        int res=0; // minimum number of rounds required (the answer to the problem).

        for(auto &x : mp) // x.second -> the frequency.
        {
            if(x.second == 1) return -1; 
            // its obvious that its not possible to do a task with frequency = 1 as we only do twos and threes of each task.

            else if(x.second%3) res += x.second/3+1; 
            // we nead at least ⌈n/3⌉ moves to finish n tasks given that n%3!=0 

            else res += x.second/3; // we can do threes only if tasksNumber%3==0
        }
        return res;
    }
};