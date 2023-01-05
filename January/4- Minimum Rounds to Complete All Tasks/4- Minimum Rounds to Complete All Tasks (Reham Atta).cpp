//Author : Reham Atta

class Solution {
public:
    // calculate the frequancy for each number in vector
    int minimumRounds(vector<int>& tasks) {
    int n = tasks.size(),cnt=0;
    map<int,int>freq;
    for(int i=0;i<n;i++) {
        freq[tasks[i]]++;git
    }
    //if freq < 2 return -1
    //if freq == 2 increase cnt by 1
    //if freq >= 3 divide taske number by 3 an add it to cnt 
    //if freq % 3 != 0 increase cnt by one after divide it by 3
    for(auto it:freq) {
        if(it.second == 1) return -1;
        else if(it.second == 2) cnt++;
        else if(it.second >= 3){
            cnt+=it.second/3;
            if(it.second%3!=0) cnt++;
          }
        }
        return cnt;
    }
};
