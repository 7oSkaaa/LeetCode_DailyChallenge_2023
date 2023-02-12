//Author : Nayra Mohammed

#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))

class Solution
{
  
  /* 
    - Main Solution idea is to use BFS to traverse through our graph from node 1 in order to get the minimum steps from node 1  to all other nodes
    with keeping in mind we only use valid paths "the edge colors alternate along the path"
  */
public:
/* 
    vis -> to calculate the minimum number of step to visite a specific node with a specific previous edge'color
    first dimension is for the nodes'id itself and second dimension is for the color of the precious edge (1 ->red , 0 -> blue , 2 -> for our root )     
    
    v-> to simulate edges as an adjacency list
    node x is connected to node y using an edge of color red " v[x].push_back({y,1})";
*/
    int vis[100][3];
    vector<vector<pair<int, int>>> v;

    void BFS(pair<int, int> st)
    {
        queue<pair<int, int>> q;// to apply BFS algo
        
        q.push(st); //push first node "root"

        vis[st.first][st.second] = 0; // the cost from root to itself = 0 
        
        while (sz(q)) // as our graph still have levels on it
        {
            st = q.front(), q.pop(); // take current node

            /*
                Then  we start traversing through its neighbours
                - We only traverse into current neighbour if and only if it has a different edge color 
                  than the current one and it wasn't visited before through that edge.
            */
            
            for (auto it : v[st.first]) 
                if (vis[it.first][it.second] == -1 && it.second != st.second)
                    q.push(it), vis[it.first][it.second] = vis[st.first][st.second] + 1;
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> ans(n); //to store the minimum number of steps to visit all nodes from node 0
        v.resize(n); //adjust our adjacency list 
        MemS(vis, -1); // initially all nodes aren't visited yet
        
        
        //simulate edges in our adjacency list
        for (auto it : redEdges)
            v[it[0]].push_back({it[1], 1});

        for (auto it : blueEdges)
            v[it[0]].push_back({it[1], 0});
        /*************************************/

        BFS({0, 2}); // start our traverse from node 0
        
        ans[0] = 0;//the number of steps from node 0 to itself equals 0

        
        for (int i = 1; i < n; i++) //store the answer for each node
        {
            if (vis[i][0] == vis[i][1] && vis[i][0] == -1) // if the node wasn't visited using any colored edge then the answer is -1
                ans[i] = -1;        
            else if (vis[i][0] != vis[i][1] && (vis[i][0] == -1 || vis[i][1] == -1))// if it was visited using one of these edges then the answer is the value of it's being visited
                ans[i] = max(vis[i][0], vis[i][1]);
            else// if it was visited using both edges then we take the minimum number of steps between them
                ans[i] = min(vis[i][0], vis[i][1]);
        }

        return ans; // return the required answer
    }
};
