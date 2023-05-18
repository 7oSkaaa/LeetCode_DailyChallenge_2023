// Author: Mahmoud Aboelsoud

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // to find the minimum number of vertices to reach all nodes we need to find the nodes with zero in degree
        // because we can reach all nodes from the nodes with zero in degree
        // we can do that by counting the in degree of each node
        // then loop over the nodes and add the nodes with zero in degree to the answer

        // in_degree: in_degree[i] -> the in degree of node i
        // ans: the answer
        vector<int> in_degree(n), ans;

        // count the in degree of each node
        for(auto&i: edges) in_degree[i[1]]++;

        // loop over the nodes and add the nodes with zero in degree to the answer
        for(int i = 0; i < n; i++){
            if(!in_degree[i]) ans.emplace_back(i);
        }

        // return the answer
        return ans;
    }
};
