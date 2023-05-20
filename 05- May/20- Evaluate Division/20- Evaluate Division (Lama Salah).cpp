// Author: Lama Salah

/*

-- THE IDEA --
Use depth-first search to traverse the graph represented by the equations and values.
Perform divisions based on the values encountered during the traversal.
Store the results in a vector and return it as the output.

----------------------------------
Step 1:
Define two maps: 'adj' and 'vis'.
- 'adj' is a mapping from a string (variable) to a vector of pairs.
  Each pair contains another string and its corresponding double value.

- 'vis' is a mapping from a string to a boolean value, indicating whether the variable has been visited
  during the depth-first search (DFS) traversal.

----------------------------------
Step 2:
Define a 'dfs' function that performs a depth-first search from the source variable 'src' to the destination variable 'des'.
The function returns a double value representing the division result of reaching 'des' from 'src'.

----------------------------------
Step 3:
In the `calcEquation` function:
- Iterate over the 'equations' and 'values' vectors to build the adjacency list.

- For each equation, add an entry in the adjacency list for both variables ('equations[i][0]' and 'equations[i][1]'),
  along with the corresponding value (values[i]) and its reciprocal (1 / values[i]).

- Initialize a vector 'ans' to store the results of the queries.

- Iterate over the 'queries' vector and perform the following steps for each query:
  - Clear the 'vis' map to mark all variables as unvisited.
  - Call the 'dfs' function with the source and destination variables from the current query.
  - Check if the destination variable was not visited during the DFS traversal.
    If so, set the result 'ans[i]' to -1; otherwise, set it to the result of the DFS traversal.

----------------------------------
Step 4:
    Return the vector 'ans' (the results of the queries).

    
*/


// -- Code --

class Solution {
public:
    map<string, vector<pair<string, double>>> adj; // Adjacency list to represent the graph.
    map<string, bool> vis; // Map to track visited variables during DFS.

    double dfs(string src, string des) {
        vis[src] = true; // Mark the current variable as visited.

        if (src == des) {
            // If the source variable is in the adjacency list, return 1; otherwise, return -1.
            return adj.count(src) ? 1 : -1;
        }

        double ans = 1; // Initialize the answer as 1.

        // Traverse through the adjacency list of the current variable.
        for (auto& [i, j] : adj[src]) {
            if (!vis[i] && !vis[des]) {
                // Recursively call dfs on unvisited variables and update the answer.
                ans = j * dfs(i, des);
            }
        }

        return ans; // Return the answer.
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build the adjacency list.
        for (int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({ equations[i][1], values[i] });
            adj[equations[i][1]].push_back({ equations[i][0], 1 / values[i] });
        }

        vector<double> ans(queries.size()); // Initialize the result vector.

        // Evaluate each query.
        for (int i = 0; i < queries.size(); i++) {
            vis.clear();  // Clear the visited map for each query.

            // Perform DFS to calculate the division result.
            double x = dfs(queries[i][0], queries[i][1]);

            // If the destination variable was not visited, set the result to -1;
            // otherwise, set it to the division result.
            ans[i] = !vis[queries[i][1]] ? -1 : x;
        }

        return ans; // Return the answers to all queries.
    }
};