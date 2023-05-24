// author: Mahmoud Aboelsoud

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // we need to calculate the value of each query
        // we can do that by using floyd warshall algorithm
        // we will build a graph where each node is a variable and each edge is an equation
        // then we will run floyd warshall algorithm to calculate the value of each query


        // st: a set to store all the strings
        set<string> st;
        // ma: a map to map each string to an index
        map<string,int> ma;

        // iterate over the equations and add the strings to the set
        for(auto&i: equations){
            st.insert(i[0]);
            st.insert(i[1]);
        }

        // initialize the index of each string
        int idx = 0, n = st.size();
        for(auto&i: st){
            ma[i] = idx++;
        }

        // initialize the distance matrix
        vector<vector<double>> dist(n, vector<double>(n, -1));


        // iterate over the equations and add the edges to the graph
        for(int i = 0; i < equations.size(); i++){
            // the equation a / b = c
            // we will add an edge from a to b with weight c
            dist[ma[equations[i][0]]][ma[equations[i][1]]] = values[i];
            // we will add an edge from b to a with weight 1 / c
            dist[ma[equations[i][1]]][ma[equations[i][0]]] = 1 / values[i];
        }


        // run floyd warshall algorithm
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0 ; j < n; j++){
                    // if there is no edge from i to k or from k to j then continue
                    if(dist[i][k] == -1 || dist[k][j] == -1) continue;

                    // if there is an edge from i to k and from k to j then add an edge from i to j with weight dist[i][k] * dist[k][j]
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }

        // ans: the answer vector
        vector<double> ans;

        // iterate over the queries and add the answer to the answer vector
        for(auto&i: queries){
            // if i[0] or i[1] is not in the set then add -1 to the answer vector
            if(!st.count(i[0]) || !st.count(i[1]))
                ans.emplace_back(-1);
            else
                // else add the value of the query to the answer vector
                ans.emplace_back(dist[ma[i[0]]][ma[i[1]]]);
        }

        // return the answer vector
        return ans;
    }
};
