// Author: Mai Ahmed Hussein

class Solution {
public:
    long long currVisit = 0;// number of visited nodes from a src node for each connected component
    
    // DFS function to traverse the graph
    void dfs(int curr, vector<int> adjacencyMatrix[], int visited[]){
        visited[curr] = 1; // Mark the current node as visited
        currVisit++; // Increment the number of visited nodes
        for(int i=0;i<adjacencyMatrix[curr].size();i++){ // Traverse all neighboring nodes
            if(visited[adjacencyMatrix[curr][i]]==0){ // If the neighbor is unvisited
               dfs(adjacencyMatrix[curr][i], adjacencyMatrix, visited);  // Perform DFS on the neighbor
            }
        }
    }
    
    
    long long countPairs(int n, vector<vector<int>>& edges){
     
        // construct the adjacency matrix
        vector<int> adjacencyMatrix[n];
        for(int i=0;i<edges.size();i++){
            adjacencyMatrix[edges[i][0]].push_back(edges[i][1]);
            adjacencyMatrix[edges[i][1]].push_back(edges[i][0]);
        }
        
        // Normal DFS
        int visited[n]; // Array to mark visited nodes
        memset(visited, 0, sizeof(visited)); // Initialize all nodes as unvisited
        long long res = 0; // Variable to store the result
        long long visitAll = 0 ;// Number of all visited nodes 
        for(int i=0;i<n;i++){ // Traverse all nodes
           currVisit = 0; // Reset the number of visited nodes for each connected component
           if(visited[i]==0){ // If the current node is unvisited
              dfs(i, adjacencyMatrix, visited); // Perform DFS on the node
              visitAll += currVisit; // Add the number of visited nodes in the current connected component to the total number of visited nodes
              res+= (currVisit)*(n - visitAll); // Calculate the number of pairs for the current connected component and add it to the result
           }   
        }
        
        return res;
    }
};
