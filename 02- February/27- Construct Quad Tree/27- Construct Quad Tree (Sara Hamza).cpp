//Author: Sara Hamza

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int n, m;

    // LeafVal : returns -1 if it is not a leaf otherwise it returns the value of this leaf (the sub grid)
    // it is a leaf if all of its cells in the sub grid have the same value
    int LeafVal(int l, int r, int t, int b, vector<vector<int>>& grid){
        int val = grid[t][l]; // get the value of this sub grid

        //check if all cells have the same value
        for(int i = t; i <= b; ++i){
            for(int j = l; j <= r; ++j){
                if(grid[i][j] != val)
                    return -1;
            }
        }
        return val;
    }

    Node* solve(int l, int r, int t, int b, vector<vector<int>>& grid){
        // base case :
        // if it is a leaf => return a leaf node with the value of the sub grid cells
        int val = LeafVal(l, r, t, b, grid);
        if(val != -1)
            return new Node(val, true);

        //construct a node with any value , mark it as a not leaf node
        Node* parent = new Node(0, 0);

        //construct its 4 children (4 sub problems)
        /*
            divide the sub grid into 2 halves : right and left (2 sub grids)
            from l -> mid and from  mid+1 -> r (inclusive)

            divide the sub grid into 2 halves : top and bottom (2 sub grids)
            from t -> mid and from mid+1 -> b (inclusive)

            so, there are 4 combinations : {top left , top right, bottom left, bottom right}
                4 subproblems ? go and solve them recursively

        */

        int mid_left_right = l + (r - l - 1)/2;
        int mid_top_bottom = t + (b - t - 1)/2;

        parent->topLeft = solve(l, mid_left_right, t, mid_top_bottom, grid);
        parent->topRight = solve(mid_left_right+1, r, t, mid_top_bottom, grid);
        parent->bottomLeft = solve(l, mid_left_right, mid_top_bottom+1, b, grid);
        parent->bottomRight = solve(mid_left_right+1, r, mid_top_bottom+1, b, grid);

        return parent;
    }

    Node* construct(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        //solve grid from 0 to n-1 inclusive and from 0 to m-1 inclusive
        return solve(0, n-1,0, m-1, grid);
    }
};
