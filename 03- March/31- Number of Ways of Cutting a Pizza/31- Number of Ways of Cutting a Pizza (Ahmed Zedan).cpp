// author : Ahmed Zedan. 
class Solution {
// solve by dp count approach 
public:
    const int mod = 1'000'000'007 ; 

    int rows , cols ; // number of rows and columns 
    int dp[51][51][11] ; // memozation 

    vector<string>pizza ; 

    // function to check if piece contains at least one apple or not 
    bool isvalid(int startrow , int endrow , int startcol , int endcol){
        for(int i=startrow ; i<=endrow ; i++){
            for(int j=startcol ; j<=endcol ; j++){
                if(pizza[i][j]=='A') return true ; 
            }
        }
        return false ; 
    }

    // recursion function 
    int rec(int i , int j , int c){
        if(!c) return 1 ; // if cut pizza k-1 cuts return 1 

        // check if call previously calculated
        int &ret = dp[i][j][c] ; 
        if(~ret) return ret ; 


        ret = 0 ; 

        // horizontal slice
        for(int row = i ; row<rows ; row++){
            bool top = isvalid(i,row,j,cols-1) ; // top peice  
            bool down = isvalid(row+1,rows-1,j,cols-1) ; // down peice 

            // check if top and down peice have apple or no 
            if(top&&down){
                // give top peice to person 
                // and try to slice down peice
                int next = rec(row+1,j,c-1) ;
                ret = (next + ret)%mod ;  
            }
        }

        // vertical  slice
        for(int col = j ; col<cols ; col++){
            bool left = isvalid(i,rows-1,j,col) ; // left peice
            bool right = isvalid(i,rows-1,col+1 , cols-1) ; // right peice
            // check if right and left peice have apple or no 
            if(left&&right){
                // give left peice to person 
                // and try to slice right peice
                int next =  rec(i,col+1,c-1) ; 
                ret = (next + ret)%mod ;
            }
        }
        return ret ; 
    }
    int ways(vector<string>& pizza, int k) {
        rows = pizza.size() , cols = pizza[0].size() ; 
        this->pizza = pizza ; 
        memset(dp,-1,sizeof(dp)) ; 
        return rec(0,0,k-1) ; 
    }
};