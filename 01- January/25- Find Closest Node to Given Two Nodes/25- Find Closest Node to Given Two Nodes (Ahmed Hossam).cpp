// Author: Ahmed Hossam

class Solution {
public:

    vector < int > BFS(int root, vector < int >& edges){
        int n = edges.size();
        
        // save the distance form the root to each node
        vector < int > dist(n, 1e9);

        // bfs queue
        queue < int > bfs;

        // add the root to the queue and make it distance is 0
        bfs.push(root);
        dist[root] = 0;

        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();

            // if the node has no outgoing edge
            if(edges[u] == -1) continue;

            // update the distance for the current node and add it to the queue
            int v = edges[u];
            if(dist[v] > dist[u] + 1)
                dist[v] = dist[u] + 1, bfs.push(v);
        }

        // return the distances
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        // get distances from node1 and node2 
        vector < int > dist_a = BFS(node1, edges), dist_b = BFS(node2, edges);
        
        // get the min of max distance of all distances
        int max_dist = 1e9, node = -1;
        for(int u = 0; u < n; u++){
            // get max_dist from node1 and node2 to the node u
            int curr_dist = max(dist_a[u], dist_b[u]);

            // update the minimum distance the answer for each node
            if(curr_dist < max_dist)
                max_dist = curr_dist, node = u;
        }

        // the index of the node that can be reach to the two nodes with minimum distance
        return node;
    }
};
