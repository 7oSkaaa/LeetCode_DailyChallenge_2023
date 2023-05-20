// Author: Noura Algohary
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // a vector to show the nodes that have incoming edges
        vector<int>reached(n, 0);
        // nodes with zero incoming edges
        vector<int>solution;

        for(auto edge:edges)
        {
            // count how many times the node is reached
            reached[edge[1]]++;
        }

        for(int node = 0;node<n;node++)
        {
            // is the node have a count of 0 incoming edges
            if(reached[node] == 0)
                solution.push_back(node);
        }

        return solution;
    }
};