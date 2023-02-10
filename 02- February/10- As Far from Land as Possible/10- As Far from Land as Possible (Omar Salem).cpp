//Author : Omar Salem
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
       // create a vector of zeros and ones
        vector<pair < int , int > >ones ,zeros;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j <n ; j++)
                (grid[i][j] ? ones.push_back({i,j}) : zeros.push_back({i,j}));
        // if  zeros or ones is empty return -1
        if(ones.empty() or zeros.empty())
            return -1;
        int ans = 0 ;
        for(auto& [a , b] : zeros){
            int Min = INT_MAX;
            for(auto& [x , y] : ones){
        // for each zero find the minimum distance to the nearest one
                Min = min(Min , abs(x - a) + abs(y - b));
            }
        // the answer is the maximum of the minimum distance
            ans = max(ans , Min);
        }
       return ans ;
    }
};