// author : ahmed zedan 
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size() ;     // number of row 
        int m = strs[0].size() ; //number of column
        int ans = 0 ;              
        for(int i=0 ; i<m ; i++){    // column
            for(int j=0 ; j<n-1 ; j++){  // row
                if(strs[j][i]>strs[j+1][i]){   // check if column not sorted
                    ans++ ; 
                    break ; 
                }
            }
        }
        return ans ; 
    }
};
