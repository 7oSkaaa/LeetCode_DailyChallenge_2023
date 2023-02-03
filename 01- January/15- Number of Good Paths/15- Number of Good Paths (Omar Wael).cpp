// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<int>root;
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        int ans=n;
        root.resize(n);
        vector<vector<int>> x(n);
        for(int i=0;i<n;i++){
            root[i]=i;
            x[i]={vals[i],1};
        }
        //sort edges according to max val
        sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
	    	return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
		});
        for(int i=0;i<edges.size();i++){
            int a,b;
            // find root of each node
            a=find(edges[i][0]);
            b=find(edges[i][1]);
            // if both nodes are equal 
            if(x[a][0]==x[b][0]){
                root[a]=b;
                // update number of paths
                ans+=x[a][1]*x[b][1];
                x[b][1]+=x[a][1];
            }
            // if not make the larger root for the another
            else if(x[a][0]>x[b][0]){
                root[b]=a;
            }else{
                root[a]=b;
            }
        }
        return ans;
    }
    // find root of this node
    int find(int x){
        if(root[x]==x){
            return x;
        }
        return root[x]=find(root[x]);
    }
};