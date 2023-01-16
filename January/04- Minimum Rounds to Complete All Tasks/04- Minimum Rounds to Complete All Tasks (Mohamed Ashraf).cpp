// Author: Mohamed Ashraf

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
	    //store frequencies
        map<int,int>m;
        for(auto i : tasks) 
		    m[i]++;
        int ans = 0;
        for(auto i : m){
            while(i.second > 1 and i.second % 3 != 0){
                i.second-=2 ;
                ans++;
            }
            // when we find a number with a frequency equals to 1 , we should return -1
            if(i.second % 3 != 0) return -1;
            
            ans += i.second/3;
        }
        return ans;
    }
};