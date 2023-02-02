//Author : Nayra Mohammed


#define sz(s) (int(s.size()))
class Solution {
public:

/*
  Our Main Solution focus on DSU :
    - Reference : ** https://www.youtube.com/watch?v=vq5u09x2Kzo&list=PLrS21S1jm43igE57Ye_edwds_iL7ZOAG4&index=8
                  ** https://cp-algorithms.com/data_structures/disjoint_set_union.html
    
  Here, We gonna reconsturct the graph into a more suitable one with regard to the needed simple path "ie. The starting node and the ending node have the same value.
  and  the starting node's value should be the maximum value along the path." that will be applied to each value as possible
  
  So, instead of considering the edges as undirected one we make it directed from node x "having a bigger value" to node y "having a smaller value".
  Also we need to store all nodes having similar values,to then consturct their new tree  individually.
  
  for each value we gonna constuct its nodes' edges again but in more convenient way to then check to then check whether these nodes in same components or not!
  Here Dsu will help us in The Checking Process as thinking in a normal way we may use  DFS , BFS , (SCC) to get whether node x is connect with node y which would be
  much slower O(n*n) but as Dsu more suitable in the updatable trees "aka. Online Queries" will achieve our target in nearly O(nlogn).
  So after connecting these nodes with their valid negihbours, we then will count how many nodes' of same value are in same component "having same parent in dsu concept" (cnt)
  Finally we add number of paths through these nodes in the form of the following equation : ( cnt * (cnt - 1) ) / 2
  
  The equation come from:
  No. nodes  || No. paths
      1            0
      2            1
      3            3
      4            6
      ...         ... 
  No.paths = ((No.nodes) * ( No.nodes - 1 ) )/ 2
  
  Why would adding them will make it result into a correct result ?
  As we already combined all nodes having same value into same components as possible so for sure  in one component we will have a path between one node of these 
  and another and it will be simple according to the fact that we adjusted the edges in the first place ! 
  
  
*/

//DSU Template
struct DSU
{
    vector<int> parent, Group_sz;
    void init(int n)
    {
        parent.resize(n), Group_sz.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i, Group_sz[i] = 1;
    }

    int Find_Leader(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = Find_Leader(parent[x]);
    }

    bool Are_Friends(int x, int y)
    {
        int x_Leader = Find_Leader(x), y_Leader = Find_Leader(y);

        return (x_Leader == y_Leader);
    }

    void Make_Them_Friends(int x, int y)
    {
        int x_Leader = Find_Leader(x), y_Leader = Find_Leader(y);

        if (x_Leader == y_Leader)
            return;
        if (Group_sz[x_Leader] > Group_sz[y_Leader])
            parent[y_Leader] = x_Leader, Group_sz[x_Leader] += Group_sz[y_Leader];
        else
            parent[x_Leader] = y_Leader, Group_sz[y_Leader] += Group_sz[x_Leader];
    }

    int Get_Group_Size(int x)
    {
        return Group_sz[Find_Leader(x)];
    }
};

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int ans = sz(vals); // initially  all nodes to itself are considered as a simple path "e.g. node x to node x"
      
        vector<vector<int>>v(sz(vals)); //our new adjusted edges
        map<int,vector<int>>Same_value; // to store all nodes having similar values
      
        for(auto it:edges)
        {
            if(vals[it[0]] > vals[it[1]]) // to connect the node having a higher value with node having a lower value
                v[it[0]].push_back(it[1]);
            else
                v[it[1]].push_back(it[0]);    
        }

        for(int i = 0; i < sz(vals); i++) // store nodes in same category according to their similarity in values "_"
            Same_value[vals[i]].push_back(i);

        DSU new_tree; //our new tree OWO
        new_tree.init(sz(vals));

        for(auto comp : Same_value){ //for each value's nodes we construct their edges with their pre_adjusted neighbours 
            for(auto node : comp.second)
                for(auto ch:v[node])
                    new_tree.Make_Them_Friends(node,ch);


            unordered_map<int,int>mp; // to store the count of  number of values'nodes in different componentes 
            for(auto node:comp.second)
                mp[new_tree.Find_Leader(node)]++;
            
            for(auto it:mp) //for each component we add their number of paths
                ans += ( ( (it.second-1) * it.second ) >> 1 );
        }
      
        return ans; //return requested answer    
    }
};
