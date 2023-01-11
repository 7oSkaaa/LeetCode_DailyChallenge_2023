// Author: Mahmoud Aboelsoud

class Solution {
public:
    // intialize the adjaceny list and the hasApple vector
    vector<vector<int>> adj;
    vector<bool> hasApple;

    // initialize variable to store the total number of apples
    int tot_apples = 0;
    
    // in this problem we use dfs to traverse the tree
    // our approch will be we go to each node if this node has an apple we add it to the total number of apples
    // then we go and travrse it's children keeping track of the total number of apples before and after traversing the child
    // if the total number of apples before and after traversing the child is different then we add 2 to the distance
    // and that means that in this subtree there is some apples so we need to go to the child and then return back to the parent 
    // which means that we have to make two moves so we add them to the distance 
    // and return the distance back to the parent to calculate the total distance 

    int dfs(int root, int par){
        // we check if the current node has an apple if it has we add it to the total number of apples
        if(hasApple[root]) tot_apples++;
        
        // we initialize the distance to 0, and a variable to store the total number of apples before traversing the children
        int prev_apples, dist = 0;

        for(auto&i: adj[root]){
            // if the child is the parent we skip it
            if(i == par) continue;
            
            // we store the total number of apples before traversing the child
            prev_apples = tot_apples;

            // we add the distance of the child to the distance of the parent
            dist += dfs(i, root);
           
            // if the total number of apples before and after traversing the child is different then we add 2 to the distance, the cost of going to and back from the child
            if(tot_apples != prev_apples)
                dist += 2;
        }
 
        return dist;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // we initialize the adjaceny list and the hasApple vector
        adj.assign(n, vector<int> ());
        this -> hasApple = hasApple;

        // we build the adjaceny list
        for(auto&i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // we call the dfs function to traverse the tree starting from the root 0 and return the distance
        return dfs(0, -1);
    }
};