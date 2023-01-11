//Author: Nayra Mohammed
class Solution {
public:
   
    vector<vector<int>>v;//our adjacency list for the graph
  
    int Dfs(int st,int pr,vector<bool>& apple){
        int tot_time = 0; //for every subgraph we enter, we need to calculate the overall time to collect the apples 

        for(auto ch:v[st])
          //avoid cycles 
            if(pr != ch){
               
               int sub_time = Dfs(ch,st,apple);//calculate the time consumed thrught the subtree starting from curr node
              
               tot_time += ((sub_time + 2) * ((sub_time > 0 || apple[ch] > 0))); 
              /*if we consumed time to collect any apples through the curr node's subtree
              or current node contains apples.. then we add the subtime + (2 back and forth through curr node) */
            }
        
        return tot_time;
    }
  
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        v.resize(n);

        for(auto it:edges) // convert the graph from describing only the edges to describe the nodes and its' negihbours (adjacency list)
            v[it[0]].push_back(it[1]), v[it[1]].push_back(it[0]);

        return Dfs(0,-1,hasApple);
    }
};
