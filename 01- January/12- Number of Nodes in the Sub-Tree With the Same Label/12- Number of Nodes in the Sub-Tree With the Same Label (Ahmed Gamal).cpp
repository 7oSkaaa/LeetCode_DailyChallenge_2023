// Author: Ahmed Gamal

class Solution {
public:

    // we want to count the number of nodes in the subtree of each node that has the same label as the node
    // we can do these type of queries by flattening the tree using dfs from the root and a timer (counter) to store the entering and exiting time of each node
    // when we re-index the nodes using their entering time, the subtree of a node will be stored in the array (of flattened tree) between entering and exiting time of the node
    // because this node will be always visited before the rest of the subtree, and will be exited only after the rest of the subtree
    

    // imagine we have to count only the nodes in the tree that have the label 'a'
    // we can flatten the tree (use entering time of each node as its index in the array) and increase the value of the array at the entering time of each node that carries the label 'a' by 1

    // after calculating the cumulative sum of the array, we can count the number of nodes in the subtree of a node by subtracting the value of the array at the entering time of the node from the value of the array at the exiting time of the node
    // we can do this for all the labels and store the results in a 2d array (prefix) (26 rows for 26 labels, and n * 2 + 10 columns for the array of the flattened tree)
    // we can calculate the answer for each node just the same as the example of the label 'a' above, but for the label of the node instead of 'a'


    // adj: the adjacency list of the tree
    vector<vector<int>> adj;
    // labels: the labels of the nodes
    string labels;
    // prefix: the cumulative sum of the array of the flattened tree
    vector<vector<int>> prefix;

    // counter: the timer
    int counter = 1;
    // time_in: the entering time of each node
    // time_out: the exiting time of each node
    vector<int> time_in, time_out;

    // dfs: the dfs function to flatten the tree
    void dfs(int src, int par){
        // increase the value of the array at the entering time of the node by 1 (at the index of the label of the node)
        prefix[labels[src] - 'a'][counter]++;
        // store the entering time of the node
        time_in[src] = counter++;

        // visit the rest of the subtree
        for(auto& nxt : adj[src]){
            // if the next node is the parent, skip it
            if(nxt == par)
                continue;
            // visit the next node
            dfs(nxt, src);
        }

        // store the exiting time of the node
        time_out[src] = counter++;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // initialize the adjacency list
        adj.assign(n, vector<int>());
        // initialize the entering and exiting times of the nodes
        time_in = time_out = vector<int>(n);
        // initialize the cumulative sum of the array of the flattened tree
        prefix.assign(26, vector<int>(n * 2 + 10));
        // store the labels of the nodes to be used in the dfs function globally
        this -> labels = labels;

        // build the adjacency list
        for(auto& edge : edges){
            // the edge is undirected
            int u = edge.front(), v = edge.back();
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        // flatten the tree
        dfs(0, -1);

        // calculate the cumulative sum of the array of the flattened tree for each label
        for(int l = 0; l < 26; l++){
            for(int i = 1; i < prefix[l].size(); i++){
                prefix[l][i] += prefix[l][i - 1];
            }
        }

        // calculate the answer for each node
        vector<int> ans;
        for(int i = 0; i < n; i++){
            // the label of the node
            int c = labels[i] - 'a';
            // the answer for the node is the value of the array at the exiting time of the node minus (the value of the array at the entering time of the node - 1)
            ans.emplace_back(prefix[c][time_out[i]] - prefix[c][time_in[i] - 1]);
        }

        // return the answer
        return ans;
    }
};