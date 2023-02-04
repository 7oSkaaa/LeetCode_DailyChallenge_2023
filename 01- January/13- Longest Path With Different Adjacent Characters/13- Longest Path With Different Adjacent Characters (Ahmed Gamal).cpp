// Author: Ahmed Gamal

class Solution {
public:

    // This problem is similar to the problem of finding the longest path in a tree (Tree Diameter)
    // At each node, we have two cases: either we include the node in the path or we don't (The diameter of the tree is passing through the node or not)
    // if we include the node in the path, we have to make sure that the node has a different label than its child (otherwise, we can't include the child in the path)
    // and in this case, the path will be the longest two paths from this node's children (to leaves) + 1 (the node itself)
    // otherwise, we try to find a path that passes through the node's children (to leaves) and we choose the longest one
    // finally, we return the length of the longest path from this node to a leaf with a different label than the node's label + 1 (the node itself) to let the parent node use it in its calculation
    

    vector<vector<int>> adj;
    int n, ans;
    string s;

    int dfs(int src){
        // mx: the longest three paths from this node's children (to leaves)
        vector<int> mx(3);

        // visit the rest of the subtree
        for(auto& nxt : adj[src]){
            // store the length to the leaf starting from the node nxt is the return value of the dfs function if it has a different label than the node src
            // otherwise, the return value will be 0
            // store it in the last element of the vector mx (the least value)
            mx[2] = dfs(nxt) * (s[nxt] != s[src]);

            // sort the vector mx in descending order to keep the longest two paths in the first two indices, and the least value in the last index
            sort(mx.rbegin(), mx.rend());
        }

        // the longest path passing through this node is the longest two paths from this node's children (to leaves) + 1 (the node itself)
        // we try to maximize the answer using this path
        ans = max(ans, mx[0] + mx[1] + 1);

        // return the length of the longest path from this node to a leaf with a different label than the node's label + 1 (the node itself) to let the parent node use it in its calculation
        return mx[0] + 1;
    }


    int longestPath(vector<int>& parent, string s) {
        n = int(s.size());
        ans = 0;
        this -> s = s;
        adj.assign(n, vector<int>());

        // build the tree
        for(int i = 0; i < n; i++){
            // if the node is the root, skip it
            if(parent[i] == -1)
                continue;
            // add the edge between the node and its parent (from the parent to the node)
            adj[parent[i]].emplace_back(i);
        }  

        // find the longest path
        dfs(0);

        // return the answer
        return ans;
    }
};