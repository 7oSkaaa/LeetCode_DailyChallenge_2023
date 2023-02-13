// Author: Mahmoud Aboelsoud

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // the idea is to use bfs and start from node 0 with color 0 (red) and color 1 (blue) and move to the next node with the opposite color
        // and store the smallest distance to reach each node in the ans array
        // we try to reach each node with both colors and store the smallest distance to reach it
        // if we reach a node with a color that we have already reached it with, we ignore it

        // two adj lists for each color
        vector<vector<int>> adjred(n, vector<int> ()), adjblue(n, vector<int> ());
        
        // fill the adj lists with the edges of each color
        for(auto&i: redEdges)
            adjred[i[0]].push_back(i[1]);
        for(auto&i: blueEdges)
            adjblue[i[0]].push_back(i[1]);
        
        // ans array to store the smallest distance to reach each node
        vector<int> ans(n, -1);
        // vis array to mark the nodes that we have already visited with a certain color
        vector<vector<bool>> vis(n, vector<bool> (2, false));
        // bfs queue
        queue<pair<int,int>> q;
        // start from node 0 with both colors 0 (red) and 1 (blue)
        q.push({0, 1});
        q.push({0, 0});
        // the distance to reach node 0 is 0
        ans[0] = 0;
        // the number of steps to reach each node
        int cnt = 0;

        // bfs loop to reach each node with both colors
        while(q.size()){
            int k = q.size();
            // increase the number of steps to reach each node
            cnt++;
            while(k--){
                auto [x, col] = q.front();
                q.pop();
                // if the node is already visited with the same color, ignore it
                if(vis[x][col]) continue;
                // mark the node as visited with the same color
                vis[x][col] = 1;

                // if the color is red, move to the next node with blue color
                if(col == 0){
                    for(auto&i: adjblue[x]){
                        // if the node is not visited before, store the number of steps to reach it
                        if(ans[i] == -1)
                            ans[i] = cnt;
                        // push the node with the opposite color to the queue
                        q.push({i, !col});
                    }
                // if the color is blue, move to the next node with red color
                }else{
                    for(auto&i: adjred[x]){
                        // if the node is not visited before, store the number of steps to reach it
                        if(ans[i] == -1)
                            ans[i] = cnt;
                        // push the node with the opposite color to the queue
                        q.push({i, !col});
                    }
                }
            }
        }
        // return the ans array
        return ans;
    }
};
