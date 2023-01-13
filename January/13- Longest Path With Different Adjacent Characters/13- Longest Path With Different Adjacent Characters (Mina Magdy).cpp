// Author: Mina Magdy

class Solution {
public:
    // declaring the answer and adjacency list
    vector<vector<int>> adj;
    int ans = 0;
    int dfs(string& s, int u = 0, int p = 0) {
        int a = 0; 	// first Maximum number
        int b = 0; 	// second Maximum number
        for (auto& v : adj[u]) {
            if (v != p) {	// if the next node isn't the parent of the current node
                if (s[v] != s[u]) {	// if the next node hasn't the same character of the current node
                    int c = dfs(s, v, u);
		    // getting first and second Maximum number on the subtree of the current node
                    if (c > a) {
                        b = a;
                        a = c;
                    }
                    else {
                        b = max(b, c);
                    }
                }
                else {
		    // if the current node has same character of the next node we just get the maximum answer for this subtree
                    ans = max(ans, dfs(s, v, u));
                }
            }
        }
	// get maximum answer for path from the first maximum number to the second maximum number
        ans = max(ans, 1 + a + b);
	// return the maximum number (path) + 1 (current node)
        return 1 + max(a, b);
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        adj.resize(n);
	// maintaining the adjacency list
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
	// calling dfs function with reference to string s (lables)
        dfs(s);
        return ans;
    }
};

/*
 * there are two possible scenarios
 * 
 * first: (when the next node has a different character of the current node)
 * we get the 2 maximum number of all its next nodes and make a path from the first maximum number to the second maximum number
 * answer: Max1 + 1 + Max2
 *
 * second: (when the next node has the same character of the current node)
 * we just get the answer of the next node without merging the current node
 * answer: is the first scenario where the currenct node will be the next node here
 *
 * dfs returnrs the maximum path of all its next node for its parent
 */
