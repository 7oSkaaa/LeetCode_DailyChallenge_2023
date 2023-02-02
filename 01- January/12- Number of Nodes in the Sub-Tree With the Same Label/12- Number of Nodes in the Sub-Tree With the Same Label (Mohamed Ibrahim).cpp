//Author: Mohamed Ibrahim

/*The solution uses depth first search (dfs) 
to traverse the tree and for each visited node 
it counts the number of occurrences of the label of the node in the subtree rooted at the current node.*/
class Solution {
public:
    // function that takes in a graph represented by 'x', an answer array 'ans', 
    // the current index 'i' and the labels of the nodes in the graph 'labels'
    vector<int> dfs(vector<vector<int>> &x,vector<int> &ans,int i,string& labels){
        // initialize an array 'a' with 26 elements all set to 0
        vector<int> a(26,0);
        // if the current node has already been visited, return the array 'a'
        if(ans[i]) return a;
        // mark the current node as visited
        ans[i]=1;
        // increment the count of the current node's label in the array 'a'
        a[labels[i]-'a']++;
        // for each child of the current node
        for(int j=0;j<x[i].size();j++){
            // recursively call the dfs function on the child node
            vector<int> b = dfs(x,ans,x[i][j],labels);
            // for each letter in the alphabet
            for(int k=0;k<26;k++){
                // add the count of the letter in the child node to the count in the current node
                a[k]+=b[k];
            }
        }
        // set the answer at the current node to be the count of the current node's label
        ans[i]=a[labels[i]-'a'];
        // return the array 'a'
        return a;
    }

    // function that takes in the number of nodes 'n', the edges of the graph 'edges' and the labels of the nodes 'labels'
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // create an adjacency list representation of the graph 'x'
        vector<vector<int>> x(n,vector<int>());
        // for each edge in the graph
        for(int i=0;i<n-1;i++){
            // add the edge to the adjacency list
            x[edges[i][0]].push_back(edges[i][1]);
            x[edges[i][1]].push_back(edges[i][0]);
        }
        // initialize an answer array 'ans' with n elements all set to 0
        vector<int> ans(n,0);
        // call the dfs function starting at the root node (node 0)
        dfs(x,ans,0,labels);
        // return the answer array
        return ans;
    }
};
