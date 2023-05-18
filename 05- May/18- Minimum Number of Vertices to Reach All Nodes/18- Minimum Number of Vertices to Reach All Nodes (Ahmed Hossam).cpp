// Author: Ahmed Hossam

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // Create two arrays to store the count of outgoing and incoming edges for each vertex
        vector<int> from(n), to(n);

        // Count the number of outgoing and incoming edges for each vertex
        for (auto& vec : edges) {
            from[vec[0]]++;  // Increment the outgoing edge count for the source vertex
            to[vec[1]]++;    // Increment the incoming edge count for the destination vertex
        }

        // Create a vector to store the result
        vector < int > res;

        // Iterate over all vertices
        for (int i = 0; i < n; i++) {
            // Check if the vertex has outgoing edges but no incoming edges
            if (from[i] && !to[i])
                res.push_back(i);  // Add the vertex to the result
        }

        // Return the result vector
        return res;
    }

};
