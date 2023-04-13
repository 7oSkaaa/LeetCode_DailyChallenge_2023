//Author: Abdelrrahman Elhaddad


// -Note: Every node has its unique number
class Solution {
public:
unordered_map<int, Node *> visited; // To store visited numbers with their refrence

Node *rec(Node *node) {
   // If we entered NULL node then we will return NULL
    if (!node)
        return NULL;

   // If the current node is visited before then return its refrence and stop traversing
    if (visited.count(node->val))
        return visited[node->val];
    
   // Creating new node with the same value
    Node *root = new Node(node->val);
   // Marking this node's value visited
    visited.insert({node->val, root});
    
   // Iterating through current's node neighbours 
   //and insert the return value in the new node's neighbours vector
    for (auto &child: node->neighbors) {
        root->neighbors.emplace_back(rec(child));
    }

    return root;
}

Node *cloneGraph(Node *node) {
    visited.clear();
    Node *root = rec(node);
    return root;
}
};
