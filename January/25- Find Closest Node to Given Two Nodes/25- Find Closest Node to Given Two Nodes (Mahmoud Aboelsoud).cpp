// Author: Mahmoud Aboelsoud

class Solution {
public:
    // the main idea is to find the distance of each node from node1 and node2
    // then find the smallest node with the minimum maximum distance from node1 and node2
    // that means we need to find the smallest node which have the minimum max(dist from node1, dist from node2)
    // we can do that by using dfs and keep the minimum distance from node1 and node2 for each node
    // then we can find the smallest node with the minimum maximum distance from node1 and node2
    // we do 2 dfs one for node1 and one for node2 as our root node to find the minimum distance from node1 and node2 for each node

    // the input edges vector 
    vector<int> edges;

    // dfs function to find the minimum distance from node1 and node2 for each node
    // we pass to the function the current node, the distance vector and the current distance from the root node
    void dfs(int node, vector<int>&dist, int cnt){
        // we check if the current distance is smaller than the minimum distance from root node to this node
        if(cnt < dist[node]){
            // if yes we update the minimum distance from root node to this node
            dist[node] = cnt;
            // then we check if there as a direct edge from this node to another node
            if(edges[node] != -1)
                // if yes we call dfs function for the next node with the current distance + 1
                dfs(edges[node], dist, cnt + 1);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        this -> edges = edges;

        // the 2 distance vectors to store the minimum distance from node1 and node2 for each node
        vector<int> dist1(edges.size(), 1e6), dist2(edges.size(), 1e6);
        
        // call dfs function for node1 and node2 as root node
        // the current distance from root node is 0
        // we pass the distance vector for each node
        dfs(node1, dist1, 0);
        dfs(node2, dist2, 0);

        // variables to store the minimum maximum distance from node1 and node2 for each node and the index of the node with the minimum maximum distance
        int ans = 1e6, idx = -1;
        // loop on all nodes
        for(int i = 0; i < edges.size(); i++){
            // check if the maximum distance from node1 and node2 for this node is smaller than the minimum maximum distance
            if(max(dist1[i],dist2[i]) < ans)
                // if yes we update the minimum maximum distance and the index of the node with the minimum maximum distance
                idx = i, ans = max(dist1[i],dist2[i]);
        }

        // return the index of the node with the minimum maximum distance if there is no node with the minimum maximum distance return -1
        return idx;
    }
};
