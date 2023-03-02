// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>values;
        int n=capital.size();
        // merge the capital and profit for each project to the same vector
        for(int i=0;i<n;i++){
            values.push_back({capital[i],profits[i]});
        }
        // sort the values
        sort(values.begin(),values.end());
        priority_queue<int> bestproject;
        int current_project=0;
        while(k--){
            // add the profits for all projects you can finish now
            while(current_project<n && w>=values[current_project].first){
                bestproject.push(values[current_project].second);
                current_project++;
            }
            // add the best profit
            if(!bestproject.empty()){
                w+=bestproject.top();
                bestproject.pop();
            }
        }
        return w;
    }
};

