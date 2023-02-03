//Author: Sara Hamza
class Solution {
public:
    string convert(string s, int numRows) {
        /*
        c -> index of rows
        a pattern is deduced
            =>ex: s of i = 0, 1, 2, 3, 4, 5, 6, 7, .. and numRows = 4
                       c = 0, 1, 2, 3, 2, 1, 0, 1, ..

            if c == 0         >> increment c till it reach numRows-1 (last row)
            if c == numRows-1 >> decrement c till it reach 0         (1st row )
            and so on

        then concatenate all rows together
        */

        //dir => direction (inc / dec)
        int n = s.size(),  c = 0, dir = 1;
        string ans = "", row[numRows];

        if(numRows == n || numRows == 1) //already in zigzag form (column || row)
            return s;

        for(int i=0; i<n; ++i){
            row[c] += s[i]; //building rows


            if(c == numRows-1) dir = -1; //dec direction
            if(c == 0) dir = 1;          //inc direction

            c += dir;
        }

        //concatenation
        for(int i=0; i<numRows; ++i){
            ans += row[i];
        }

        return ans;
    }
};
