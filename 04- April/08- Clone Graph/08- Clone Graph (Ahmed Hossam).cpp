// Author: Ahmed Hossam

class Solution {
public:
    
    // Define an unordered map to store the nodes and their copies
    unordered_map < int, Node* > mp;

    // Define a function to clone the given graph
    Node* cloneGraph(Node* node) {
        // If node is NULL, return the node
        if (node == NULL) return node;

        // If the node already exists in the map, return its copy
        if (mp.count(node -> val)) return mp[node -> val];

        // Create a vector to store the neighbors of the current node and add the current node to the map
        mp[node -> val] = new Node(node -> val, {});

        // Recursively clone the neighbors of the current node and add them to the copy's neighbors vector
        for (auto& newNode : node -> neighbors) {
            Node* newNeighbors = cloneGraph(newNode);
            mp[node -> val] -> neighbors.push_back(newNeighbors);
        }

        // Return the copy of the given node
        return mp[node -> val];
    }
};
