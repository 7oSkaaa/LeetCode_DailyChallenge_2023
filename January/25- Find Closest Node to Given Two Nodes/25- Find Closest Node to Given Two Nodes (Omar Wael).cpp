// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size(),ans=-1,mndist=INT_MAX;
        //dist1 store the distance from node1 to all the neighbour nodes and dist2 store the distance from node2 to all the neighbour nodes
        vector<int> dist1(n, 0), dist2(n, 0);
        //visited array to identify wheather we visited particular node form node1 and node2
        vector<bool> vis1(n, false), vis2(n, false);
        dfs(node1,edges,vis1,dist1);
        dfs(node2,edges,vis2,dist2);
        for(int i=0;i<n;i++){
            // if current node visited from node1 and node2 and and the max distance from those nodes is less than the min distance
            if(vis1[i] && vis2[i] && mndist>max(dist1[i],dist2[i])){
                // update the min distance and the answer
                mndist=max(dist1[i],dist2[i]);
                ans=i;
            }
        }
        return ans;
    }
    void dfs(int cur, vector<int>& edges, vector<bool>& vis, vector<int>& dist){
        vis[cur]=true;
        if(edges[cur]!=-1 && vis[edges[cur]]==false){
            dist[edges[cur]]=dist[cur]+1;
            dfs(edges[cur],edges,vis,dist);
        }
    }
};