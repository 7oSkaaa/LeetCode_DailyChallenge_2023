// Author: Mahmoud Aboelsoud

class Solution {
public:
    // intialize parent vector and the string s which are the input parameters to use globally 
    vector<int> parent;
    string s;
    
    // intitialize adjacency list to store the tree and the answer variable
    vector<vector<int>> adj;
    int ans = 0;

    // my main idea is to get the 2 maximum paths from each node and add them together then add 1 to them to get the longest path
    // with different adjacent characters
    // because we traverse the tree from root we can't get the longest path directly from the root
    // so we have to get the 2 maximum paths from each node and add them together then add 1 to them to get the longest path with different adjacent characters 
    // to do so we use a priority queue to get the 2 maximum paths from each node
    // then we check if the priority queue is empty or has 1 element or has 2 elements
    // if it's empty then the longest path with different adjacent characters is 1
    // if it has 1 element then the longest path with different adjacent characters is the element in the priority queue + 1
    // if it has 2 elements then the longest path with different adjacent characters is the 2 elements in the priority queue + 1
    // then we check if the node is the root or not
    // if it's not the root then we check if the node and the parent have the same character or not
    // if they have the same character then we return 0
    // if they have different characters then we return the longest path with different adjacent characters
    // if it's the root then we return 0


    // dfs function to traverse the tree and calculate the longest path with different adjacent characters
    int dfs(int node, int par){
        // priority queue to get the 2 maximum paths from each node
        priority_queue<int> pq;
        for(auto&i: adj[node]){
            // to avoid going back to the parent
            if(i == par) continue;
            // push the longest path with different adjacent characters from each child to the priority queue
            pq.push(dfs(i, node));
        }

        // check if the priority queue is empty or has 1 element or has 2 elements
        if(pq.size() == 0){
            // if it's empty then the longest path with different adjacent characters is 1
            ans = max(ans, 1);
            // if it's not the root then we check if the node and the parent have the same character or not
            if(par != -1)
                // if they have the same character then we return 0 otherwise we return 1
                return s[node] != s[par];

        }else if(pq.size() == 1){
            // if it has 1 element then the longest path with different adjacent characters is the element in the priority queue + 1
            ans = max(ans, pq.top() + 1);
            // if it's not the root then we check if the node and the parent have the same character or not
            if(par != -1){
                // if they have the same character then we return 0 otherwise we return the longest path with different adjacent characters
                if(s[node] == s[par]) return 0;
                return pq.top() + 1;
            } 
        }else{
            // we get the 2 maximum paths from the priority queue
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            // if it has 2 elements then the longest path with different adjacent characters is the 2 elements in the priority queue + 1
            ans = max(ans, x + y + 1);
            // if it's not the root then we check if the node and the parent have the same character or not
            if(par != -1)
                // if they have the same character then we return 0 otherwise we return the longest path with different adjacent characters
                if(s[node] == s[par]) return 0;
                return x + 1;
        }
        // if it's the root then we return 0
        return 0 ;
    }

    

    int longestPath(vector<int>& parent, string s) {
        // assign the input parameters to the global variables
        this -> parent = parent;
        this -> s = s;
        
        // get the number of nodes 
        int n = parent.size();
        // initialize the adjacency list
        adj.assign(n, vector<int> ());

        // build the adjacency list
        for(int i = 1; i < n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        
        // call the dfs function to traverse the tree and calculate the longest path with different adjacent characters
        dfs(0, -1);

        // return the longest path with different adjacent characters
        return ans;
    }
};
