// Author: Ahmed Hossam

class Solution {
public:

    vector < vector < int > > adj, freq;
    vector < int > ans;
    string labels;

    // merge two nodes together
    void merge(vector < int >&  a, vector < int >& b){
        for(int i = 0; i < 26; i++)
            a[i] += b[i];
    }

    // make undirected edge between u and v
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p){
        // add the  current char to the current frequency vector
        freq[u][labels[u] - 'a']++;

        for(auto& v : adj[u]){
            if(v == p) continue;
            dfs(v, u);
            
            // merge the frequencies vectors together
            merge(freq[u], freq[v]);
        }

        // ans[u] is the number of nodes in the subtree with label[u]
        ans[u] = freq[u][labels[u] - 'a'];
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this -> labels = labels;
        adj = vector < vector < int > > (n);
        freq = vector < vector < int > > (n, vector < int > (26)); 
        ans = vector < int > (n);

        // make adjacency list using edges
        for(auto& edge : edges)
            add_edge(edge[0], edge[1]);
        
        // get the answer;
        dfs(0, -1);

        // the required answer
        return ans;
    }
};
