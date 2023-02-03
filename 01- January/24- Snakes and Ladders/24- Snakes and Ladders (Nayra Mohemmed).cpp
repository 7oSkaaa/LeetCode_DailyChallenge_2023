//Author : Nayra Mohammed

#define sz(s) (int(s.size()))
/*
to get minimum moves reaching the final cell n*n ,the most appropriate algo would be Bfs as our moves is like our levels in graph
So we may convert the transition between any cell to other into a directed graph
*/
class Solution {
public:
    //trans -> to store where each cell traverse
    // vis -> to know whether current cell was visited before or not to prevent cyclic trverse
    int trans[401],vis[401]={0};
    
    int BFS(pair<int,int>st,int n){
        // queue to implement BFS Algo
        queue<pair<int,int>>q; // pair<int,int> where first element is current cell and the second is the number of steps we consumed till reaching it 
        q.push(st); //push base state
        vis[st.first]++; // base cell "1" is visited 
      
        while(sz(q)){
            st=q.front(),q.pop();
            
            if(st.first == n) // if we reached our goal then return number of steps
                return st.second;
            
            for(int i = st.first + 1;i <= min(st.first+6,n);i++) // try each 6-sided die roll options (move "1,2,...,6" steps once)
                if(!vis[trans[i]])
                    q.push({trans[i],st.second+1}),vis[trans[i]] = 1; // push current state and mark the cell we gonna visit as visited
        }


        return -1; // if we didn't return anyvalues before then it's immpossible to go from cell 1 to cell n
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        
      // Here we process our board into readable and easier form (cell x either traverse u to itself or to other cell "using ladders or snakes")
        int x = 1;
        reverse(board.begin(),board.end()); //start our board from cell 1 
        
        for(int i = 0 ,op ;i < sz(board) ; i++){
            op = ((i&1) ? -1 : 1); // dealing with 0_based rows (left to right) : odd rows cell's value decreases but even rows cell's value increases
            
            // if current cell contains neither a ladder nor snake then it transver into itself otherwise it transver into other cell
            // update x values for next cell in same row
            for(int j = 0 ; j < sz(board[i]) ; j++)
                trans[x]=(board[i][j] == -1 ? x : board[i][j]),x += op;  
          
            // Calculating the starting cell for next row from left side
            x = 1 + ((i+1) * sz(board));
         
            x += ( ( (i%2 == 0) * sz(board) )-(i%2 == 0) );  
        }

        return BFS({1,0},sz(board)*sz(board)); //return answer
    }
};
