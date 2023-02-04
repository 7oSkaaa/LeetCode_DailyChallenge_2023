// Author: Ahmed Gamal
// beats 97.32% in runtime

class Solution {
public:
    // the minimum number of steps to pick and apple and come back to where you started, is the number of edges between you and the apple multiplied by 2
    // so we need to find the number of edges between the root and the apples
    // we will only add the number of edges between the root and the nodes to the answer an apple is on the path from the root to the apple
    // so we will do a dfs and for each node we will return the number of edges between the root and the node and if the path down has an apple or not
    // if the node has an apple we will add the number of edges between the end of our path and the node to the answer
    // if the path down doesn't have an apple we will add 0 to the number of edges
    // if the path down has an apple we will add the number of edges between the end of our path and the node to the answer, and update the second of our pair to state that we found and apple on the path down 

    vector<vector<int>> adj;
    vector<bool> has;

    // first: number of edges between the root and the end of the path
    // second: if the path down has an apple or not

    pair<int, int> dfs(int src, int par){
        // cnt: number of edges between the root and the ends of the paths down that have apples
        // ok: if the path down has one apple at least or not (0: no, 1: yes)
        int cnt = 0, ok = 0;

        for(auto& nxt : adj[src]){
            // if the node is the parent of the current node we will skip it, to avoid recalling the parent
            if(nxt == par)
                continue;   
            
            // tmp: the return value of the dfs call on the child of the current node
            auto tmp = dfs(nxt, src);
            
            // if the path down has an apple we will add the number of edges between the end of our path and the node to the answer
            cnt += tmp.first * tmp.second;

            // if the path down has an apple we will update the second of our pair to state that we found an apple on the path down through the current node
            ok |= tmp.second;
        }

        // the number of edges starting from the current node to the apples plus one (the current node has been added to the answer)
        // if the path down has an apple, or the current node has an apple 

        return {cnt + 1, ok | has[src]};
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // adj: the adjacency list of the tree
        adj.assign(n, vector<int>());

        // building the adjacency list
        // for each edge we will add the two nodes to each other's adjacency list
        // because the tree is undirected
    
        for(auto& edge : edges){
            adj[edge.front()].emplace_back(edge.back());
            adj[edge.back()].emplace_back(edge.front());
        }
        // has: if the node has an apple or not (to be used in the dfs globally)
        this -> has = hasApple;

        // tmp: the return value of the dfs call on the root
        auto tmp = dfs(0, -1);
        
        // subtract one because the root has been added to the answer and there's no need for edges to go to the root
        // multiply the length of the path by 2 because we need to go back to the root
        return --tmp.first * 2;
    }
};