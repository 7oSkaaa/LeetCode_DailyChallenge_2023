//Author: Nayra Mohammed

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) //in case having one row ,then the original string will have no changes
            return s;
        
        vector<string>v(numRows); // for every row , we store characters that match it existence to that row
        string ans; // to store our final answer
        
        int i = 0, j = 0; // i -> to know which column we are
                          // j -> to know in which row we are
      
        // in even column our pointer 'j' increases for next upcoming character. Otherwise ,It decreases
        for(auto it: s){

            v[j] += it; // add curren character to current row
            
            if(!(i & 1)) // if we are in an even column then, we increase j for next character "going down"
                j++;
            else // Otherwise, we having a cross ! so we decrease it "going up" 
                j--;

            if(!(i & 1) && j == numRows) //being in an even column that means  j increases till reaching its limit "numRows", then we switch into the next column
                j = numRows - 2, i++;    //with j equal to a new value 'the previous row we stored in - 1' for the upcomping character
            else if((i & 1) && j == -1) //being in an odd column that means j decreases till reaching its limit "-1",then we switch into next column and
                j = 1, i++;             // with j  equal to an new value 'the previous row we stored in + 1' for the upcoming character 
            
        }

        for(int i = 0 ;i < numRows;i++)
                ans += v[i]; // add each string we stored for all rows
        
        return ans; // return the required answer
    }
};
