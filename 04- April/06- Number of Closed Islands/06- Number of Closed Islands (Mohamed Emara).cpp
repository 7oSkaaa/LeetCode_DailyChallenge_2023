
// Author: Mohamed Emara

class Solution {
public:
    int arr[110][110];
    int vis[110][100];
    int n, m;

    bool touch_borders = 0;       // to check if I touched the borders
    // Note that if the island touches any border, This is not a closed island

    void dfs(int i, int j)
    {
        // return if I'm out of the borders or in the water
        if(i<0 || j<0 || i>=n || j>=m || arr[i][j] == 1 || vis[i][j])
            return;

        // If this island connected to any border --> touch_borders=1 
        // not to take it as a closed island    
        if(i == 0 || j == 0 || i == n-1 || j == m-1)
            touch_borders = 1;

        // visit all neighbours 
        if(arr[i][j] == 0)
        {
            vis[i][j] = 1;
            dfs(i+1, j);
            dfs(i-1, j);
            dfs(i, j+1);
            dfs(i, j-1);
        }   
    }

    int closedIsland(vector<vector<int>>& grid) {

	// ============= IDEA ============= //
	/*
	    to count the number of closed islands, We have to visit all cells
	    at each cell, See all neighbours of this cell up, down, right, left recursively
	    We only interested in '0' cells 
	    Mark all visited cells not to take it in another components
	    a component starts from '0' cell is valid if it's surrounded by all ones
	    to know that, our component mustn't touch any of grid borders 
	    when every cell and its visiting neighbours terminates (visited all it neighbers)
	    check for any visit of i==0 or j==0 or i==n-1 or j==m-1
	    if neigther of them happend increment the number of islands
	*/


        // fill the global arr[][]
        n = grid.size();
        m = grid[0].size();

        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        
        for(int i=0; i<n; i++)
        {
            vector<int>v;
            v = grid[i];
            for(int j=0; j<m; j++)
            {
                arr[i][j] = v[j];
            }
        }     

        int closed_islands = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // check in only zeros & unvisited cells
                if(!arr[i][j] && !vis[i][j])
                {
                    dfs(i, j);
                    // if this component connected to the borders don't increment closed_islands
                    if(!touch_borders)
                        closed_islands ++;

                    // reset the touch_borders in the next component
                    touch_borders = 0;
                }
            }
        }   
        
        return closed_islands;

    }
};


