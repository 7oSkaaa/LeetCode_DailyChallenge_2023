//Author: Mohamed Ibrahim
class Solution {
public:
    string convert(string s, int numRows) {
        // If the number of rows is 1, the pattern will be a straight line,
        // so we can simply return the original string
        if (numRows == 1) return s;

        // Create a vector of strings, where each element represents a row
        vector<string> rows(min(numRows, int(s.size())));

        // curRow keeps track of the current row we are on
        int curRow = 0;
        // goingDown indicates the direction we are moving (up or down)
        bool goingDown = false;

        // For each character in the input string,
        for (char c : s) {
            // add the character to the current row
            rows[curRow] += c;
            // If we have reached the top or bottom row, change direction
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            // Update the current row
            curRow += goingDown ? 1 : -1;
        }

        // Combine all the rows into a single string
        string res;
        for (string row : rows) res += row;
        return res;
    }
};
