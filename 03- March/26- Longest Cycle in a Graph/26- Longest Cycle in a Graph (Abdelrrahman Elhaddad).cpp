//Author: Abdelrrahman Elhaddad

//Note: each node can not be in more than one cycle

class Solution {
public:
int n, ans = -1;
vector<bool> visited; // To mark visited nodes in all DFS traverals
map<int, int> ccVisited; // To mark visited nodes in each DFS traversal to detect cycles

void DFS(int i, int steps, vector<int> &edges) {
    visited[i] = true;
    ccVisited[i] = steps;

    if (edges[i] != -1 && ccVisited.count(edges[i])) // If the neighbour node is visited in the same DFS traversal that means there is a cycle
        ans = max(ans, ccVisited[i] - ccVisited[edges[i]] + 1);  // Compare the difference between the lenght between the max length ans store the max
  
    if (edges[i] != -1 && !visited[edges[i]]) //If the neighbour node not visited inany DFS traversal, Then enter it and continue traversing
        DFS(edges[i], steps + 1, edges);
}

int longestCycle(vector<int> &edges) {
    ans = -1; // Re-initialize ans value 
    n = edges.size();
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ccVisited.clear(); // Clear the ccVisited map each DFS traversal
            DFS(i, 0, edges);
        }
    }
    return ans;
}
};
