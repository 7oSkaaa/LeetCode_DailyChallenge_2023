// Author: Ahmed Hossam

class Solution {
public:

    int largestPathValue(const string& colors, vector<vector<int>>& edges) {
        // Initialize variables 'n', 'maxFreq', and 'visited' with initial values.
        int n = colors.size(), maxFreq = 0, visited = 0;
        
        // Initialize a vector called 'adj' with size 'n'.
        vector < vector < int > > adj(n);
        
        // Initialize a vector called 'deg' with size 'n'.
        vector < int > deg(n);
        
        // Initialize a vector called 'freq' with size 'n x 26', and all elements initialized to 0.
        vector < vector < int > > freq(n, vector < int > (26));
        
        // Loop through each vector in the 'edges' vector.
        for(auto& vec : edges){
            // Add the second element in the current vector to the adjacency list of the first element.
            adj[vec[0]].push_back(vec[1]);
            // Increment the degree of the second element.
            deg[vec[1]]++;
        }
        
        // Initialize a queue called 'topo'.
        queue < int > topo;
        
        // Loop through each element in the range [0, n).
        for(int v = 0; v < n; v++)
            // If the degree of the current element is 0, add it to the queue.
            if(!deg[v])
                topo.push(v);
                
        // While the queue is not empty:
        while(!topo.empty()){
            // Get the front element of the queue.
            int u = topo.front();
            
            // Remove the front element from the queue.
            topo.pop();
            
            // Increment the visited counter.
            visited++;
            
            // Update the maximum frequency seen so far.
            maxFreq = max(maxFreq, ++freq[u][colors[u] - 'a']);
            
            // Loop through each element in the adjacency list of the current element.
            for(auto& v : adj[u]){
                // Decrement the degree of the current element.
                if(--deg[v] == 0)
                    // If the degree of the current element is 0, add it to the queue.
                    topo.push(v);
                
                // Loop through each character in the range ['a', 'z'].
                for(char c = 'a'; c <= 'z'; c++)
                    // Update the frequency of the current character in the adjacency list of the current element.
                    freq[v][c - 'a'] = max(freq[v][c - 'a'], freq[u][c - 'a']);
            }
        }
        
        // If all elements have been visited, return the maximum frequency seen so far. Otherwise, return -1.
        return visited == n ? maxFreq : -1;
    }

};
