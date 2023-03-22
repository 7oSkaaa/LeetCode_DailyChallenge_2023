//Author: Abdelrrahman Elhaddad

/*
 Intuition:
  If we want to find the minimum edge which I can pass on through my way to the n node,
  Then we have to find the minimun edge in the same connected component that contains 1 and n node
*/

class Solution {
private:
const int oo = 0x3f3f3f3f; // Our INFINITY value

public:
vector<vector<pair<int, int>>> graph; // Declaring graph vector to store all of our edges
vector<bool> visited; // To mark visited nodes
int mn = oo;

void DFS(int i) {
    if (visited[i]) // If I entered a visited node then stop traversing that way and return 
        return;
  
    visited[i] = true; // Marking current node as visited
  
    for (auto &child: graph[i]) {
        mn = min(mn, child.second); // Getting the minimum edge
        DFS(child.first); // Move to the next node
    }
}

int minScore(int n, vector<vector<int>> &roads) {
    graph.resize(n + 1);
    visited.resize(n + 1);
  
    for (int i = 0; i < roads.size(); i++) {
      // Storing our edges both ways because our graph is bidirectional
        graph[roads[i][0]].emplace_back(roads[i][1], roads[i][2]); 
        graph[roads[i][1]].emplace_back(roads[i][0], roads[i][2]);
      }
  
    DFS(1); // Starting to traverse through the graph from node 1
  
    return mn;
  }
};
