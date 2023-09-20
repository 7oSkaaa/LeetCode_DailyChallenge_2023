// Author: Ahmed Hossam

class Solution {
public:
    // Declare variables for adjacency list, depth and degree
    vector < vector < int > > adj;
    vector < int > depth, deg;

    // Function to initialize adjacency list, depth and degree
    void init(int n){
        adj.assign(n + 10, vector < int > ());
        depth.assign(n + 10, 0);
        deg.assign(n + 10, 0);
    }

    // Function to add edges to the adjacency list and increment degree of destination node
    void add_edge(int u, int v){
        adj[v].push_back(u);
        deg[u]++;
    }

    // Function to perform topological sort and return true if possible, false otherwise
    bool topology (int n){
        queue < int > topo;
        vector < int > graph;

        // Push all nodes with degree 0 into the queue
        for(int i = 0; i < n; i++)
            if(deg[i] == 0) topo.push(i), deg[i]--;

        // Perform topological sort
        while(!topo.empty()){
            int curr_node = topo.front();
            topo.pop();
            graph.push_back(curr_node);

            // Decrement degree of all neighbors and push them into queue if degree becomes 0
            for(auto& new_node : adj[curr_node]){
                deg[new_node]--;
                if(deg[new_node] == 0)
                    topo.push(new_node);
            }
        }

        // Return true if all nodes have been visited, false otherwise
        return graph.size() == n;
    }

    // Function to check if all courses can be finished
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        init(numCourses);

        // Add all prerequisites as edges to the adjacency list
        for(auto& pr : prerequisites)
            add_edge(pr[0], pr[1]);

        // Perform topological sort and return result
        return topology(numCourses);
    }
};
