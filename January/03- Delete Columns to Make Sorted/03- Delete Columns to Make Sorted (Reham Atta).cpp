//Author : Reham Atta

class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        int cnt=0;
        // iterate word size as a row (all sizes are equal)
        // iterate vector size as columns
        // check if letter greater than the next letter increase cnt by one and break from this column 
        for(int i=0;i<str[0].size();i++){
            for(int j=0;j<str.size()-1;j++) {
                if(str[j][i] > str[j+1][i]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};