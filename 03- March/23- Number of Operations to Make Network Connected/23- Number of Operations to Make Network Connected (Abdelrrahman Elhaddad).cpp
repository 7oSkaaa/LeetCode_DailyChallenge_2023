//Author: Abdelrrahman Elhaddad

/*
 Intuition:
    To know how many times that we will have to extract certain cables between two directly connected computers 
    and place them between any pair of disconnected computers, We will need to know two things:
    1- Is there enough cables to connect all the devices?
      We will know that by checking if we have cables more than or equal n - 1
      - If we have 4 computers we will need 3 cables. [o-o-o-o] -> 4 computers, 3 cables
    2- How many disconnected computers we need to connect?
      We will know that by using DFS to traverse through the graph
      and count how many connected components exist in our graph
 */

class Solution {
private:
    vector<vector<int>> graph; // To store graph edges
    vector<bool> visited; // To mark visited nodes

public: 
    void DFS(int i) {
        visited[i] = true; // Mark current node as visited
        for (auto &child: graph[i]) {
            if (!visited[child]) // If the child node is not visited, Then we will enter it
                DFS(child);
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections) {
        graph.resize(n);
        visited.resize(n);

        if (connections.size() < n - 1) // Checking if we have enough edges to connect all of the computers
            return -1; // If no return -1

        // Pushing every node's childs
        // Pushing both ways because our cables are bidirectional
        for (auto &conn: connections) { 
            graph[conn[0]].emplace_back(conn[1]);
            graph[conn[1]].emplace_back(conn[0]);
        }
      
        int c = -1; // Initalizing our counter with -1
      
        for (int i = 0; i < n; i++) { // Iterating on all the nodes to check the unvisited
            if (!visited[i]) { // If not visited, Enter it and increment the counter by 1
                DFS(i);
                c++;
            }
        }
      
        return c; // Return the counter
    }
};
