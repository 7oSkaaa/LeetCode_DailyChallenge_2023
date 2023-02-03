// Author: Ahmed Hossam

class Solution {
public:

    int longestPath(vector<int>& parent, string s) {
        // decalration variables to use
        int n = parent.size();
        vector < int > top_1(n, 1), top_2(n, 1), deg(n);
        
        // add edges between i and parent of i
        for(int i = 1; i < n; i++)
            deg[parent[i]]++;
        
        // queue for topology sort
        queue < int > topo;

        // let's calc the max_path
        int max_path = 1;

        // add the endpoints in queue
        for(int i = 1; i < n; i++)
            if(deg[i] == 0)
                topo.push(i), deg[i]--;
        
        auto update_max = [&](int u, int x){
            // update the maximum to paths for each node
            if(x >= top_1[u])
                top_2[u] = top_1[u], top_1[u] = x;
            else if(x >= top_2[u])
                top_2[u] = x;
        };

        while(!topo.empty() && topo.front()){
            // the current node
            int u = topo.front(), p = parent[u];
            topo.pop();

            // path_length
            int len = 1 + (s[u] != s[p] ? top_1[u] : 0);
            
            // update max paths for current node
            update_max(p, len);

            // if the parent degree becomes 0 so, let's add it
            if(!--deg[p])
                topo.push(p);

            // update the answer wit max between it and the best two paths in it's children
            max_path = max(max_path, top_1[p] + top_2[p] - 1);
        }

        // the length of the longest path with the required conditions.
        return max_path;
    }
};