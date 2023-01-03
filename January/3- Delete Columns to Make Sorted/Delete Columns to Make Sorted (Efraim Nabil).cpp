// author: Efraim Nabil
class Solution {
public:
    int minDeletionSize(vector < string >& s) {
        int c = 0;
        for(int i = 0; i < size(s[0]); i++){        // columns
            for(int j = 1; j < size(s); j++){       // rows
                if(s[j][i] < s[j - 1][i]){          // if any char is smaller than the previous one in the same column
                    c++;                            // then we need to delete this column
                    break;
                }
            }
        }
        return c;
    }
};