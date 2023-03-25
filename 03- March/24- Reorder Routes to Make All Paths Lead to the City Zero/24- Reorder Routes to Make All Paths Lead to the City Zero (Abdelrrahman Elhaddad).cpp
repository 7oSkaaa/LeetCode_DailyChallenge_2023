//Author: Abdelrrahman Elhaddad

/*
  Intuition:
    If we want to know which roads will be redirected, Then we will need to count the roads that
    head from the parent of the tree to the child as my optimal situation is to have all the roads directed for the parent to the child.
    We will do that by storing all the roads both ways and storing the redirected roads in a set, So if we use them through our traversing we count them.
    We will use DFS for traversing the tree
  */

class Solution {
public:
vector<vector<int>> graph; //To store graph edges
unordered_set<string> changed; //To store redirected edges
int c = 0; //count edges

void DFS(int i, int parent) { //Traversing through the tree
    for (auto &child: graph[i]) {
        if (child != parent) {
            DFS(child, i);
          
            if (changed.count(to_string(i) + '_' + to_string(child))) //If the edge we are using is redirected increment the counter
                c++;
        }
    }
}

int minReorder(int n, vector<vector<int>> &connections) {
    graph.resize(n);
    c = 0;
  
    for (auto &conn: connections) { //Storing edges
        graph[conn[0]].emplace_back(conn[1]); //Storing the undirected edge
        changed.insert(to_string(conn[1]) + '_' + to_string(conn[0])); // Storing the redirected edge in the set
        graph[conn[1]].emplace_back(conn[0]); //Storing the redirected edge
    }
  
    DFS(0, -1);
  
  // Subtract the counter from n-1 and return it as in the traversal we were traversing from the 0 node,
  // But in the problem we want to travel from the other nodes to the 0 node
    return n - 1 - c; 
  }
};
