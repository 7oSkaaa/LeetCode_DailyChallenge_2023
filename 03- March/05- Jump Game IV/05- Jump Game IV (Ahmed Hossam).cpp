// Author: Ahmed Hossam

class Solution {
public:
    int minJumps(vector<int>& arr) {
        // number of elements
        int n = arr.size();

        // adjacent list for each number with the indices that appears in it
        map < int, vector < int > > adj;
        for(int i = 0; i < n; i++)
            adj[arr[i]].push_back(i);

        // make distance vector to get the minimum distance for each index
        vector < int > dist(n, 1e9);

        // make bfs started from index 0
        queue < int > bfs;
        bfs.push(0);
        dist[0] = 0;

        // to check it's valid indices to add to the current queue or not
        auto add = [&](int u, int v) -> void {
            if(v < 0 || v >= n) return;
            if(dist[v] > dist[u] + 1)
                dist[v] = dist[u] + 1, bfs.push(v);
        };

        // make bfs to get the minimum distance for each index
        while(!bfs.empty()){
            // the current index
            int u = bfs.front();
            bfs.pop();

            // check can i add the next index to me
            add(u, u + 1);

            // check can i add the prev index to me
            add(u, u - 1);

            // try to move to the index of any element same number of me
            for(auto& v : adj[arr[u]])
                add(u, v);

            // clear the adjacent list for the current element to avoid redundancy
            adj[arr[u]].clear();
        }

        // return the minimum distance to reach last element
        return dist[n - 1];
    }
};
