// Author: Mohamed Amr

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // return zero if the vector of strings is empty
        if(strs.empty())
            return 0;
        // n = length of any string in the vector
        int n = strs[0].size();
        // st contains the indices of the columns deleted
        set<int>st;
        for(int i=1; i<strs.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                // compare each char with the char in the row above it.
                if(strs[i][j] < strs[i-1][j])
                    st.insert(j);
            }
        }
        // ans is the size of the set
        return st.size();
    }
};