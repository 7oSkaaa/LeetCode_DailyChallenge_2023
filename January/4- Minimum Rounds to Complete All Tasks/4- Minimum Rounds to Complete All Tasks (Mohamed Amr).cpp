class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>occ;
        for(auto& i:tasks)
            occ[i]++;
        
        int count = 0;
        for(auto& [f,s]:occ)
        {
            if(s==1)
                return -1;
            else if(s%3==0)
                count += s/3;
            else
            {
                count += s/3+1;
            }
        }
        return count;
    }
};