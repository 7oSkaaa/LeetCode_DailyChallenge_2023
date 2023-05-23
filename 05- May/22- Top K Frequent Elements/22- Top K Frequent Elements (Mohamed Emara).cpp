// Author: Mohamed Emara

class Solution {
public:
    // Firstly, We want to calculate the frequency of each value in the vector
    // Secondly, We want to sort them in an ascending order
    // return a vector of first k elements
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Store the frequency of each value in mp
        map<int, int>mp;
        for(auto it : nums) {
            mp[it] ++;
        }

        // Add the values of mp to tmp but with (value, key)
        // to be able to sort them based on the freqecny of each value
        vector<pair<int, int>>tmp;
        for(auto it : mp)
            tmp.push_back({it.second, it.first});

        // sort & reverse to guarantee that the first k element have the 
        // maximum frequecny.
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        
        int cnt = 0;

        // Store the values of the most frequent element 
        vector<int>res;
        for(auto it : tmp) {
            res.push_back(it.second);
            cnt ++;

            // if the values taken from tmp = k  --->  break.
            if(cnt == k)
                break;
        }
        return res;
    }
};

