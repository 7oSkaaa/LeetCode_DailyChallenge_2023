// Author: Mahmoud Aboelsoud

class Solution {
public:
    string convert(string s, int n) {
        
        // our zigzag will be like this if we have n = 3
        /*
            0        4       8
              1   3    5   7
                2        6
        */
        // so we try to build each row and then concatenate them
        // we will use a map to store each row string
        // we will use a variable to indicate the current row
        // we will use a boolean variable to indicate if we are going down or up
        // we will iterate over the string and add each character to the current row
        // if we are going down and we reach the last row we will change the direction
        // if we are going up and we reach the first row we will change the direction
        // if we are going down we will increment the row
        // if we are going up we will decrement the row
        // after we finish iterating over the string we will concatenate the rows and return the result
        // if n == 1 we will return the string as it is because the pattren will look like this 
        // 0 1 2 3 4 5 

        // if n == 1 return the string as it is
        if(n == 1) return s;
        // map to store each row string
        map<int,string> ma;
        // current row
        int row = 1;
        // boolean variable to indicate if we are going down or up
        bool down = 1;

        // iterate over the string
        for(auto&i: s){
            // add each character to the current row
            ma[row] += i;
            // if we are going down and we reach the last row we will change the direction
            if(row == n && down) down = !down;
            // if we are going up and we reach the first row we will change the direction
            else if(row == 1 && !down) down = !down;

            // if we are going down we will increment the row
            if(down) row++;
            // if we are going up we will decrement the row
            else row--;
        }

        // concatenate the rows and return the result
        string ans = "";
        for(auto&[x,y]: ma)
            ans += y;

        return ans;
    }
};
