class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int ,int>mp;
        //using a hash map to know the number of repetions of a task
        for(int &task : tasks)
            mp[task]++;
        int ans = 0;
        for(auto &[key,num] : mp)
        {
            if(num == 1)
                return -1;
          //every number consists of 2 & 3 except 1
            ans+=ceil(num/3.0);
            
        }
        return ans;
    }
};
