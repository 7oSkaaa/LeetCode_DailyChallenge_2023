// Author: Salma Khaled
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // count number of coloumns to be deleted
        int cnt=0;
        //iterate through coloumns
        for(int i=0; i<strs[0].size(); i++){
        // iterate each character in the column
            for(int j=0; j<strs.size()-1; j++){
                if(strs[j][i] > strs[j+1][i]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
