//Author: Abdullah Moemen


class Solution {
public:
vector<pair<int,bool>>arr[101];
int vis[101][3];
int bfs(int dist)
{
    memset(vis,0,sizeof vis);
    queue<pair<int,int>>q;
    q.push({0,-1});
    int lvl=0;
    while(q.size())
    {
        int sz=q.size();
        while(sz--)
        {
            int node=q.front().first;
            int clr=q.front().second;
            q.pop();
            if(node==dist)return lvl;
            for(auto e:arr[node])
            {
                if(!vis[e.first][e.second]&&clr!=e.second)
                {
                    q.push({e.first,e.second});
                    vis[e.first][e.second]=1;
                }
            }
        }
        lvl++;
    }
return -1;
    
}
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        //we will iterate over all nodes and run BFS every time from source(0) to current node (node[i]) to calculate shortest distance. 
        //in BFS: if i reach current node from  (redEdge) then when i go to child node i only visit child node that have (blueEdge) with current node, and vise versa.
        
        for(int i=0;i<redEdges.size();i++)
        {
            arr[redEdges[i][0]].push_back({redEdges[i][1],0});
        }
        for(int i=0;i<blueEdges.size();i++)
        {
            arr[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=bfs(i);
        }
        return ans;
    }
};