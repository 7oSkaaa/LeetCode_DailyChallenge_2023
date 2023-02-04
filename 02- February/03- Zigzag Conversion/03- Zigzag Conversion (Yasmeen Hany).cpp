// Author : Eileanora

class Solution {
public:
    string convert(string s, int numRows) {
        int sz = s.size();
        vector <string> v(numRows); 
        int i = 0; // current char to be added 
        while(i < sz) 
        {
            // to construct our zigzag we add charcaters to each row until we reach the last one
            for(int row = 0; row < numRows && i < sz; row++)
                v[row] += s[i++];
            
            // now we go up by adding one char per row until we go back to the first row
            for(int row = numRows - 2; row > 0 && i < sz; row--)
                v[row] += s[i++];

            // this pattern goes on until i reaches the end of the string
        }
        // now we just concatenate all the rows to get the final answer
        string ans;
        for(auto& i : v) 
            ans += i;
        return ans;
    }
};