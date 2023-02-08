// Author: Ahmed Hossam

class Solution {
public:
    string convert(string& s, int n) {
        // if n == 1 there is no change will be
        if(n == 1) return s;

        // vector of string for each row to add the characters
        vector < string > grid(n);

        // r -> index for current row, idx current char of the string
        int r = 0, idx = 0, sz = s.size();
        while(idx < sz){
            // iterate to fill the column down 
            while(idx < sz && r < n) grid[r++] += s[idx++];
            r--;
            // iterate fo fill up the rows except the first and last one
            while(idx < sz && r > 0) grid[--r] += s[idx++];
            r++;
        }

        // the result string will be the concatenation of the all rows
        string conv;
        for(auto& str : grid)
            conv += str;
        return conv;
    }
};
