// Author: Ahmed Gamal

// for this problem, we want to find the longest cycle in the graph
// since every node has at most one edge, we can just start from any node and follow the edges until we reach a node that we have already visited
// then we need to check if this edge is a back edge or not
// if it is a back edge, then we have found a cycle and can update the answer
// otherwise, we can just ignore this edge

class Solution {
    vector<int> time_in, time_out;
    int timer, ans;
public:

    void dfs(int src, vector<int>& edges) {
        // mark the node as visited using the current time
        time_in[src] = timer++;

        // get the next node
        int nxt = edges[src];

        // if the next node is not -1
        if(~nxt){
            // if the next node is visited and not exited, then we have found a cycle (back edge)
            if(time_in[nxt] and not time_out[nxt]) {
                // update the answer with the length of the cycle
                ans = max(ans, time_in[src] - time_in[nxt] + 1);
            } else if(not time_in[nxt]) {
                // if the next node is not visited, then start dfs from it
                dfs(nxt, edges);
            }
        }

        // mark the node as exited using the current time
        time_out[src] = timer++;
    }

    void init(int n) {
        // time_in: the time when a node is visited for the first time
        // time_out: the time when a node is exited
        time_in = time_out = vector<int>(n + 5);

        // timer: the current time
        timer = 1;

        // ans: the answer
        ans = -1;
    }

    int longestCycle(vector<int>& edges) {
        // n: the number of nodes
        int n = int(edges.size());

        // init the data structures
        init(n);

        for(int i = 0; i < n; i++) {
            // if the node is not visited, then start dfs from it
            if(not time_in[i]) {
                dfs(i, edges);
            }
        }

        return ans;
    }
};