//Author : Omar Salem
class Solution {
public:
    int DFS (int node , int &globalMax , vector < vector < int > > &tree , 
    string &s ){
        priority_queue<int, vector<int>, greater<int>> MaxTwo; // create a pq to return Max 2 values 
        MaxTwo.push(0),MaxTwo.push(0); 

        for(auto &child : tree[node]) // DFS on tree
        {
            int MaxFromChild = DFS(child , globalMax , tree , s);
            
            if(s[child] != s[node]){ // chech two node are valid ---> a -> a not valid / a->b valid 
                 MaxTwo.push(MaxFromChild); // get a max 2 values 
                 MaxTwo.pop();
            }
        }
        int Max2 = MaxTwo.top() ; MaxTwo.pop();
        int Max1 = MaxTwo.top() ; MaxTwo.pop();

        globalMax = max(globalMax,1+Max1+Max2); // return max path 

        return Max1+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector < vector < int > >tree(n); // convert arr to tree 
        for(int i = 1 ; i < n ;i++)
            tree[parent[i]].push_back(i);
        int globalMax = 0;
        DFS(0,globalMax,tree,s); // call DFS
        return globalMax; 
    }

};
