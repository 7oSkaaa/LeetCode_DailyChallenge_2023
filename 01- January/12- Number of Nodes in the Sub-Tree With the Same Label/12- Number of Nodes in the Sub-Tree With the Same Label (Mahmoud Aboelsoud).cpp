// Author: Mahmoud Aboelsoud

class Solution {
public:
    // intialize the adjaceny list, labels string and the answer vector
    string labels;
    vector<vector<int>> adj;
    vector<int> ans;

    // dfs function to count the number of nodes in the subtree with the same label
    // and return vector with the count of all labels in the subtree
    // then added the subtree count to the current node count
    // after we traverse all children of the current node then the answer of the current node equals the cnt of the label in all it's subtrees
    
    vector<int> dfs(int root, int par){
        // cnt vector to count the number of nodes in the subtree with the same label
        vector<int> cnt(26, 0);

        // add 1 to the count of the label of the current node
        cnt[labels[root] -  'a']++;
    
        // traverse all children of the current node
        for(auto&i: adj[root]){
            // if the child is the parent then continue
            if(i == par) continue;

            // get the count of all labels in the subtree of the child
            vector<int> child_cnt = dfs(i, root);

            // add the count of all labels in the subtree of the child to the current node count
            for(int i = 0; i < 26; i++)
                cnt[i] += child_cnt[i];
        }

        // the answer of the current node equals the count of the label in all it's subtrees + 1(the node label itself) which is added in the start of the function
        ans[root] = cnt[labels[root] - 'a'];
        
        // return the cnt vector to it's parent
        return cnt;
    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this -> labels = labels;
        adj.assign(n, vector<int> ());
        ans.assign(n, 1);
        
        // build adjaceny list from the edges vector
        for(auto&i: edges){ 
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // traverse the tree from it's root 0
        dfs(0, -1);

        // return the answer vector
        return ans;
    }
};
