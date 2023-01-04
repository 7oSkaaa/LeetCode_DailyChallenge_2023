// Author: Salma Khaled
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
    	// create a hashmap to get frequency of each number
        unordered_map<int, int>mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }
        int ans=0;
        for(auto it = mp.begin(); it != mp.end(); it++){
        	// if it was repeated one time
            if(it->second == 1){
                return -1;
            }
            // if it's divisible by 3 we don't have to do any task two times
            else if(it->second % 3 == 0){
                ans+= it->second/3;
            }
            // else we just get the remaning
            else{
                ans+=(it->second/3)+1;
            }
        }
        return ans;
    }
};
