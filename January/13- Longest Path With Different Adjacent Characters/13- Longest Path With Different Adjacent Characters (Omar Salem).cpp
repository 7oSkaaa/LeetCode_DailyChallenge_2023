//Author : Omar Salem
class Solution {
public:
    int DFS (int node , int &globalMax , vector < vector < int > > &tree , 
    string &s ){
        priority_queue<int, vector<int>, greater<int>> MaxTwo;
        MaxTwo.push(0),MaxTwo.push(0); 

        for(auto &child : tree[node])
        {
            int MaxFromChild = DFS(child , globalMax , tree , s);
            
            if(s[child] != s[node]){
                 MaxTwo.push(MaxFromChild);
                 MaxTwo.pop();
            }
        }
        int Max2 = MaxTwo.top() ; MaxTwo.pop();
        int Max1 = MaxTwo.top() ; MaxTwo.pop();

        globalMax = max(globalMax,1+Max1+Max2);

        return Max1+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector < vector < int > >tree(n);
        for(int i = 1 ; i < n ;i++)
            tree[parent[i]].push_back(i);
        int globalMax = 0;
        DFS(0,globalMax,tree,s);
        return globalMax; 
    }

};