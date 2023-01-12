//Author: Nayra Mohammed

class Solution {
public:
  
    vector<int>ans; // here to store our answer (count childs having same node's label in its subtree
    int frq[26] = {0}; // count frequencies of each label
    vector<vector<int>>v; //adjacency list for our graph
    string x;//here we store labels as a global variable
    
  /*
  main soltuion idea: for each subtree, we save how many similar labels we counted before, then we traverse through its childs
the answer for current node will equal to 
                  (how many similar labels we counted after visiting its childs) - (how many similar labels we counted before visiting its childs)
    
  */
    void Dfs (int st,int pr){
       
       int pre = frq[x[st] - 'a'];//here we store how many similar labels we counted before visiting the actual subtree for current node 'st'
   
       for(auto ch:v[st])//visit every child for current node
            if(pr != ch)//check it's not the parent of current node (avoide cyclic traverse)
                Dfs(ch,st);//traverse through this child
        
        frq[x[st]-'a']++;  //increase frequency of current node's label by one (adding 1 for node's label itself)  
        
        //answer for current node = the difference between the overall frquency of current node'label and the overall frequency of it before processin' its subtree 
        ans[st] = frq[x[st]-'a'] - pre; 
    }
  
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        //costimize our graph's adjacency list's size,and our answer'size
        ans.resize(n),v.resize(n);
        x = labels; // initialize x as a duplicate of labels to use it globally
        
        for(auto it:edges)//convert graph to be simualted as an adjacency list
            v[it[0]].push_back(it[1]),v[it[1]].push_back(it[0]);

        Dfs(0,-1);//proccessing our answer
      
        return ans;
    }
};
