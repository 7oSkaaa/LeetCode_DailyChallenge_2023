// author : Omar Sanad

class Solution {
public:
    // a map that works as an adjacency list,
    // for each element we store its neighbours and the cost to reach them from this element
    map < string, vector < pair < string, double > > > adj;
    map < string, bool > vis;
    double dfs(string node, string target) {
        if (adj.find(node) == adj.end() || adj.find(target) == adj.end())
            return 0;
        
        // we have reached the target node, we have completed the query equation
        if (node == target) return 1;

        // we mark this symbol as visited, to avoid cycles
        vis[node] = true;

        // we initialize a variable to store the answer in it
        double ret = 0;

        // we iterate over all the neighbours of this node, (in other words, all the variables that the current variable has a direct relationship with them in the equations vector)
        for (auto &[child, val] : adj[node])
            // if this neighbour was not visited yet, then we can search for the answer using the path leading to it
            if (not vis[child]) {
                // store the answer of this path
                double Tmp = val * dfs(child, target);

                // if the answer of this path equals 0, then we cannot reach the target using this path, so we don't store the answer in the ret variable,
                // otherwise, we have reached the answer using this path, so we update the ret variable
                if (Tmp != 0)
                    ret = Tmp;
            }

        // we return the current calculated answer
        return ret;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        // we can represent this problem as a graph
        // the adjacency list will hold for each element the neighbours and the cost to go to these neighbours
        // Given : equations[i] = [Ai, Bi],,,, Ai / Bi = values[i]
        // Then : from Ai to Bi ----> the cost is 1 / values[i]
        //        from Bi to Ai ----> the cost is values[i]
        for (int i = 0; i < equations.size(); i++)
            adj[equations[i].front()].emplace_back(equations[i].back(), 1 / values[i]),
            adj[equations[i].back()].emplace_back(equations[i].front(), values[i]);
        
        // a vector to store the answer to the queries
        vector < double > Answer;

        // iterate over all the queries to calculate its answer
        for (auto &q : queries) {
            // clear the visited array, as we are gonna do a new dfs
            vis.clear();

            // declare a variable to store the answer of the dfs, answer to the current query
            double curr = dfs(q.back(), q.front());

            // if the answer of this query equals 0, then we cannot calculate this query, (in other words, we cannot find a relationship between the the symbols in this query),
            // so we push -1 , to mark as not found
            if (curr == 0)
                Answer.push_back(-1.0);
            // else then we push the answer of the current query
            else
                Answer.push_back(curr);
        }

        // return the vector answer, (the answer of the queries);
        return Answer;
    }
};
