//Author : Omar Salem
class Solution {
public:
    string convert(string s, int n) {
        // if num Of Row == 1 then all char in s has a same row 
        if(n == 1)
            return s;
        // create grid of string     
        vector < string > grid(n);
        int rowIndex = 0 ;
        bool MoveDown = true;
        for(auto &i : s)
        {
            // add the char to the current row
            grid[rowIndex] += i;
            // If we have reached the bottom then change direction
            if(rowIndex == n - 1) 
                MoveDown = false;
            // If we have reached the top then change direction
            else if (rowIndex == 0)
                MoveDown = true;
            // Update the current row
            rowIndex += (MoveDown ? 1 : -1);
        }
        //concatenation all the rows into a single string
        string ans ;
        for(auto &i : grid)
            ans += i;

        return ans ;
    }
};