// Author: Walaa AbdElhady

class Solution {
private:
    bool vis[401][2];//each node has two color
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>ans(n, -1);// store depth of each node
        ans[0] = 0;
        vector<vector<pair<int, int>>>adj(n, vector<pair<int, int>>(n));
        // adjacency list each adjacent pair will be {node , color} of the edge
        for (auto& node : redEdges)adj[node[0]].push_back({ node[1], 1 });// 1=> redColor
        for (auto& node : blueEdges)adj[node[0]].push_back({ node[1], 0 });// 0=>blueColor
        // make bfs from 0 to each node
        queue<vector<int>>q;
        q.push({ 0,1 });
        q.push({ 0,0 });
        int dep = -1;
        while (!q.empty()) {
            int sz = q.size();
            dep++;// after each level increament the depth 
            while (sz--) {
                auto p = q.front();
                q.pop();
                // current node and current color
                int node = p[0], color = p[1];
                vis[node][color] = true;
                for (auto& ch : adj[node]) {
                    // if we did nt visit this node before and colors are alternative update the depth
                    if (!vis[ch.first][ch.second] && ch.second != color) {
                        if (ans[ch.first] == -1) {
                            ans[ch.first] = dep + 1;
                        }
                       // update path of new node
                        q.push({ ch.first,ch.second });
                    }
                }
            }
        }
        return ans;
    }

};