// Author: Noura Algohary
class Solution {
public:
    int dfs(int current_node, vector<vector<int>>& children_nodes, string& s, int& final_path)
    {
        // the final path is the longest one produced from the first two longest paths of children of the same node
        int first_longest_path = 0, second_longest_path = 0, child_path = 0;

        for(auto child_node : children_nodes[current_node])
        {
            child_path = dfs(child_node, children_nodes, s, final_path);

            if(s[child_node] == s[current_node])
                continue;

            // keep tracking the first two longest paths
            if(child_path > first_longest_path)
            {
                second_longest_path = first_longest_path;
                first_longest_path = child_path;
            }
            else if(child_path > second_longest_path)
            {
                second_longest_path = child_path;
            }
        }
        final_path = max(final_path, first_longest_path + second_longest_path + 1);

        return ++first_longest_path; // increment by 1 to count the node itself
    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> children_nodes(parent.size());
        int final_path = 1; // one node is the minimum

        for(int i = 1;i<parent.size();i++) // start from node 0 (index = 1)
        {
            children_nodes[parent[i]].push_back(i); 
        }

        dfs(0, children_nodes, s, final_path);

        return final_path;
    }
};