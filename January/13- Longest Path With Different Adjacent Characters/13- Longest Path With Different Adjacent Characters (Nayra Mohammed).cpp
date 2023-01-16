//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution {
public:
    vector<vector<int>>v;//adjacency list for graph
    vector<pair<int,int>>mx; //for each node,we save the maximum 2 path we can go from it to the furthest child 
    string x; //use s globally
    
    pair<int,int> Max_Path(int st,int pr){
        int mx_path1,mx_path2;
        mx_path1 = mx_path2 = 0; // the 2 maximum paths through node 'st'

        for(auto ch:v[st])
            if(ch != pr ){ // avoid cyclic traverse
               
                pair<int,int> mx_path = Max_Path(ch,st); //process through node's child
                
                if(x[st] != x[ch]){ // in case our node's child is different in label.. we can decide whether to take its maximum path or not.
                
                  if(mx_path1 < max(mx_path.first,mx_path.second)) // if the pre mx path1 is less than the max path through node's child then we take it
                    mx_path2 = max(mx_path2, mx_path1), mx_path1 = max(mx_path.first,mx_path.second);
                  // we process mx_path2 to have the max value between itself and the pre mx path1 as we need the maximum 2 paths !!
                
                  else if(mx_path2 < max(mx_path.first,mx_path.second))// otherwise if  the pre_maximum path2 is less than the max path through node's child then we take it 
                    mx_path2 = max(mx_path.first,mx_path.second);    
                }
            }

        mx[st] = {mx_path1 + 1,mx_path2 + 1};    //adding one for current node st
    
        return  mx[st];  
    }

    int longestPath(vector<int>& parent, string s) {
        int ans = 0; // our max answer 
      
        x = s; // x is a duplicate of s
        v.resize(sz(parent)),mx.resize(sz(parent)); // adjust our adjacency list & mx paths 's sizes 

        for(int i = 1;i < sz(parent); i++) // simulate our graph as adjacency list 
            v[i].push_back(parent[i]),v[parent[i]].push_back(i);

        Max_Path(0,-1); // process paths

        for(int i = 0;i < sz(mx) ; i++)//find the longest path passin' through node i
            ans = max(ans,mx[i].first + mx[i].second - 1); // subtract 1 to avoid the duplicate count of the same node

        return ans;
    }
};
