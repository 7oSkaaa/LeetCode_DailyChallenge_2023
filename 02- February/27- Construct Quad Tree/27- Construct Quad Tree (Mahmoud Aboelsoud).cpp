// Author: Mahmoud Aboelsoud

class Solution {
public:
    // the idea is to divide the grid into 4 parts and check each part if it is all 0 or all 1
    // if it is all 0 or all 1 then we can make a leaf node with the value of the part
    // else we will make a parent node and call the function recursively on the 4 parts 

    // the input grid
    vector<vector<int>> grid;
    // dimension of the grid
    int n;

    // summation function to get the sum of the part and the number of elements in it
    auto sum(int st_x, int en_x, int st_y, int en_y){
        int tot = 0, cnt = 0;
        for(int i = st_x; i < en_x; i++){
            for(int j = st_y; j < en_y; j++){
                tot += grid[i][j];
                cnt++; 
            }
        }
        // return the sum and the number of elements
        return make_pair(tot, cnt);
    }

    // build function to build the tree
    Node* build(int st_x, int en_x, int st_y, int en_y){
        // get the sum and the number of elements in the part
        auto [tot, cnt] = sum(st_x, en_x, st_y, en_y);

        // if the part is all 0 or all 1 then we can make a leaf node
        if(tot == 0 || tot == cnt){
            // make a leaf node with the value of the part
            Node* nw = new Node(tot/cnt, 1);
            // return the node
            return nw;
        }

        // if the part is not all 0 or all 1 then we will make a parent node and call the function recursively on the 4 parts
        // get the mid point of the part to divide it into 4 parts
        int midx = en_x - (en_x - st_x) / 2, midy = en_y - (en_y - st_y) / 2;
        
        // make a parent node
        Node* nw = new Node(0, 0);

        // call the function recursively on the 4 parts
        nw -> topLeft = build(st_x, midx, st_y, midy);
        nw -> topRight = build(st_x, midx, midy, en_y);
        nw -> bottomLeft = build(midx, en_x, st_y, midy);
        nw -> bottomRight = build(midx, en_x, midy, en_y);
        
        // return the parent node
        return nw;
    }

    Node* construct(vector<vector<int>>& grid) {
        // set the input grid and the dimension of the grid
        this -> grid = grid;
        n = grid.size();
        
        // call the build function to build the tree and return the root node of the tree
        return build(0, n, 0, n);
    }
};
