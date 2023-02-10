// author: Esraa Syam
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // create a vector of zeros and ones
        // store the index of each zero and one in the vector
        vector < pair < int , int > > zeros , ones;
        int n = grid.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0) zeros.push_back({i , j});
                else ones.push_back({i , j});
            }
        }
        // if there is no zeros or ones return -1
        if(zeros.empty() or ones.empty()) return -1;
        int ans = 0;
        // for each zero find the minimum distance to the nearest one
        // the answer is the maximum of the minimum distances
        for(auto& [x , y] : zeros){
            int mini = INT_MAX;
            for(auto& [i , j] : ones){
                mini = min(mini , abs(x - i) + abs(y - j));
            }
            ans = max(ans , mini);
        }
        return ans;  
    }
};