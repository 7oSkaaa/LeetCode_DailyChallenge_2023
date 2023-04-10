// Author: Ahmed Gamal

// for this problem, we want to clone the given graph
// to solve this problem, we can use dfs to traverse the graph and create a copy of it
// we can use a map to store the nodes that we have already created, so we don't create a new node for the same node in the graph
// we can use a vector to store the nodes that we have already visited, so we don't visit the same node twice
// and once we meet a connection between two nodes, we can add the new node to the neighbors of the current node

class Solution {
public:

    // original: the current node in the original graph
    // cpy: the current node in the copy of the graph
    // vis: vector to store the nodes that we have already visited
    // get_node: map to store the nodes that we have already created
    void dfs(Node* original, Node* cpy, vector<bool>& vis, map<int, Node*>& get_node) {
        // mark the current node as visited
        vis[original -> val] = true;

        // traverse the neighbors of the current node
        for(auto& nxt : original -> neighbors) {
            // if the current neighbor is not created yet, create it
            if(get_node.find(nxt -> val) == get_node.end()) {
                get_node[nxt -> val] = new Node(nxt -> val);
            }

            // add the current neighbor to the neighbors of the current node in the co
            cpy -> neighbors.emplace_back(get_node[nxt -> val]);

            // if the current neighbor is not visited yet, visit it
            if(not vis[nxt -> val]) {
                dfs(nxt, cpy -> neighbors.back(), vis, get_node);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        // if the graph is empty, return nullptr
        if(not node) {
            return nullptr;
        }

        // create the root of the copy of the graph
        auto root = new Node(node -> val);

        // map to store the nodes that we have already created
        map<int, Node*> get_node;
        
        // vector to store the nodes that we have already visited
        vector<bool> vis(101);

        // store the root in the map
        get_node[node -> val] = root;
        
        // traverse the graph and create a copy of it
        dfs(node, root, vis, get_node);
        
        // return the root of the copy of the graph
        return root;
    }
};