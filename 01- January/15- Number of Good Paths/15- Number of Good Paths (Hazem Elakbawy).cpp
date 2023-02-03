// Author : Hazem Elakbawy
class Solution
{
public:
    int find(vector<int>&parent,int a)
    {
      if (a==parent[a])
        return a;
      parent[a]=find(parent,parent[a]);// go up to root
      return parent[a];
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges)
    {
      int n=vals.size();
      vector<int>parent(n);
      unordered_map<int,int>freq; // count nodes
      unordered_map<int,int>max_;
      for(int i=0;i<n;i++)
      {
        parent[i]=i; // each node has same node as its parent
        max_[i]=vals[i]; // each node is maximum of itself
        freq[i]=1; 
      }
      sort(edges.begin(),edges.end(),[&](const vector<int>&a,vector<int>&b)
      {
        int m=max(vals[a[0]],vals[a[1]]);
        int n=max(vals[b[0]],vals[b[1]]);
        return m<n;
      });
      int res=0;
      for(auto &edge : edges)
      {
        // find parents of both nodes in each edge
        int a=find(parent,edge[0]); 
        int b=find(parent,edge[1]);
        // make larger as the root
        if (max_[a]!=max_[b])
          max_[a]>max_[b]?parent[b]=a:parent[a]=b; // make larger as its roots
        else
        {
          parent[a]=b;
          //  #paths from a (with freq: n) to b (with frequency : m) which are equal :: ==> m * n paths 
          res+=freq[a]*freq[b];
          freq[b]+=freq[a];
        }
      }
      return res+n;  // each node is considered as path to itself (+n)
    }
};