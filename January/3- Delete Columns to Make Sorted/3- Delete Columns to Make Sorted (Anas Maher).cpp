Author: Anas Maher

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n = strs.size(), res = 0; // n = number of strings, res = deleted columns.
        
        int sz = strs[0].size(); // size of first string (which is the same for all strings). 


        // s = abc bce cae
        // first column is {a, b, c} = {s[1][1], s[2][1], s[3][1]}
        // second column is {b, c, a} = {s[1][2], s[2][2], s[3][2]}
        // third column is {c, e, e} = {s[1][3], s[2][3], s[3][3]}

        // let j = word pointer, a column is s[j++][columnNumber]. 
        for(int i=0 ; i<sz ; i++)
        {
            for(int j=1; j<n ; j++)
            {
                if(strs[j][i] < strs[j-1][i])
                {
                    res++; break;
                }
            }
        }
        return res;
    }
};