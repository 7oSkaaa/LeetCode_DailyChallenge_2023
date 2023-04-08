// author : Omar Sanad
class Solution {
public:
    // the 4 adjacent directions
    vector<pair<int,int>>dxy4={{1,0},{0,1},{0,-1},{-1,0}};

    int comp[505][505]; // the component id where the cell x,y exists

    int currId = 0; // to keep track of the current component id

    int n, m;   // n number of rows     // m number of columns

    int cells_inComp[500 * 500]{};  // cells_inComp[ID] // the number of cells in the component with this id "ID"
    
    bool bad_comp[500*500]; // if this connected component touches the boundaries of the grid

    // the grid itself
    vector<vector<int>> grid;

    // validate if this cell is in the grid
    bool valid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    //  dfs function
    void dfs(int x, int y) {
        //  assign an id for this cell
        comp[x][y] = currId;

        // increase the number of cells in the current connected component
        cells_inComp[currId]++;

        // iterate over the 4 adjacent cells
        for (auto &[dx, dy] : dxy4) {
            int nx = dx + x, ny = dy + y;

            // if the current adjacent cell is not valid, then the current connected component touches the boundaries of the grid 
            if (not valid(nx, ny))  bad_comp[currId] = true;

            // else if the current adjacent cell has the value of one, and it wasn't visited before, then explore this cell
            else if (grid[nx][ny] and not comp[nx][ny])
                dfs(nx, ny);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size(), m = grid.front().size();

        // iterate over the whole grid, if the curr cell is not visited, then explore this cell
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] and not comp[i][j])
                    currId++, dfs(i, j);
        
        //  iterate over the connected components, if the component doesn't touch the boundaries of the grid,
        // then add to the result the number of cells in this component
        int result = 0;
        for (int i = 1; i <= currId; i++)
            if (not bad_comp[i])
                result += cells_inComp[i];
        
        return result;
    }
};
