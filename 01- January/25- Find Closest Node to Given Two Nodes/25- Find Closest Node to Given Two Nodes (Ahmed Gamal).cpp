// Author: Ahmed Gamal

class Solution {
public:

    // we need to find a common node that node1 and node2 that the maximum distance from them is the minimum possible
    // in similar problems we can use BFS to find the shortest path from node1 to each node and the shortest path from node2 to each node (dfs will give wrong answers since we need the shortest path)
    // but in this problem there's no multiple outgoing edges from each node, so we can use dfs exactly like we do in tree problems (there's only one way to go from each node to another)
    // we can use a vector to store the distances from node1 to each node and another vector to store the distances from node2 to each node


    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // n: the number of nodes
        const int n = (int)edges.size();

        // dist_a: the distances from node1 to each node
        vector<int> dist_a(n, -1);
        // dist_b: the distances from node2 to each node
        auto dist_b = dist_a;
        // vis: a vector to mark the visited nodes
        vector<bool> vis(n);

        // dfs: a lambda function to do dfs
        // src: the current node
        // depth: the depth of the current node (the distance to the current node)
        // dist: the distances from the starting node to each node
        auto dfs = [&](auto dfs, int src, int depth, vector<int>& dist) -> void {
            // mark the current node as visited
            vis[src] = true;
            // update the distance to the current node
            dist[src] = depth;

            // if the current node has an outgoing edge and the next node is not visited we need to go to the next node
            // notice that we didn't use a loop here because we know that there's only one way to go from each node to another
            int nxt = edges[src];
            if(~nxt and not vis[nxt]){
                dfs(dfs, nxt, depth + 1, dist);
            }
        };


        // do dfs from node1
        dfs(dfs, node1, 0, dist_a);
        // reset the visited nodes
        vis.assign(n, false);
        // do dfs from node2
        dfs(dfs, node2, 0, dist_b);

        // ans: the answer (the common node that node1 and node2 that the maximum distance from them is the minimum possible)
        // mn: the minimum possible maximum distance
        int ans = -1, mn = INT_MAX;

        for(int i = 0; i < n; i++){
            // a: the distance from node1 to the current node
            // b: the distance from node2 to the current node
            int a = dist_a[i];
            int b = dist_b[i];

            // if the current node is a common node and the maximum distance from it to node1 and node2 is the minimum possible we need to update the answer
            if(~a and ~b){
                if(max(a, b) < mn){
                    mn = max(a, b);
                    ans = i;
                }
            }
        }

        // return the answer
        return ans;
    }
};