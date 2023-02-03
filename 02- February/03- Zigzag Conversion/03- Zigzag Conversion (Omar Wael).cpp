// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    string convert(string s, int numRows) {
        // 2D vector to store zigzag pattern
        vector<vector<char>>rows(numRows);
        // row -> current row
        // cur -> current index
        int row=0,cur=0;
        // check if you going up or down (true = down )
        bool forward=true;
        while(cur<s.size()){
            rows[row%numRows].push_back(s[cur]);
            cur++;
            // if you reach last row then go up 
            if(row==numRows-1){
                forward=false;
            }// if you reach first row then go down
            else if(row==0){
                forward=true;
            }
            // if you going down increase the row
            if(forward){
                row++;
            }// if you going up decrease the row
            else{
                row--;
            }
        }
        // read the new word
        string ans="";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<rows[i].size();j++){
                ans.push_back(rows[i][j]);
            }
        }
        return ans;
    }
};