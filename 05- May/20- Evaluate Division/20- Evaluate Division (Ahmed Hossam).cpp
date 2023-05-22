// Author: Ahmed Hossam

class Solution {
public:
    
    unordered_map < string, unordered_map < string, double > > graph;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        for (int i = 0; i < equations.size(); i++) {
            auto equation = equations[i];
            string a = equation[0];
            string b = equation[1];
            double value = values[i];

            graph[a][b] = value;
            graph[b][a] = 1 / value;
        }

        vector < double > res;
        for (auto it : queries) {
            string start = it[0];
            string end = it[1];
            // Calculate the result using breadth-first search
            double ans = bfs(start, end);
            res.push_back(ans);
        }
        return res;
    }

    double bfs(string& start, string& target) {
        // check if current and target nodes exist in the graph
        if (graph.find(start) == graph.end() || graph.find(target) == graph.end())
            return -1;

        queue < pair < string, double > > q;
        q.push({start, 1});

        unordered_set < string > vis;
        vis.insert(start);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            string node = curr.first;
            double value = curr.second;

            // if current node is the target
            if (node == target)
                return value;

            // Traverse the neighbors of the current node
            for (auto neighbor : graph[node]) {
                string next = neighbor.first;
                // check if the neighbor has not been visited before
                if (vis.find(next) == vis.end()) {
                    vis.insert(next);
                    // multiply the current value by the value of the edge to the neighbor
                    q.push({next, value * neighbor.second});
                }
            }
        }
        return -1;
    }
};
