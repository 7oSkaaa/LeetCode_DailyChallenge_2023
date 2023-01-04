// Author: Zeinab Mohy

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<vector<int>>v;
        int k=0,kk=0;
        //loop the whole word to separate each index
        for(int i=0;i<strs[0].size();i++){
            vector<int>vv;
            for(int ii=i;k<strs.size();){
                string x=strs[k];
                //push each char which has the same index to make them in one column
                vv.push_back(x[ii]);
                k++;
            }
            //push each column to make vector of columns
            v.push_back(vv);
            k=0;
        }
        int c=0;
        for(int i=0;i<v.size();i++){
            vector<int>ans;
            //push columns in new vector to check them
            for(int ii=0;ii<v[i].size();ii++){
                ans.push_back(v[i][ii]);
            }
            //check each column if it sorted or not
            if(is_sorted(ans.begin(),ans.end())==false){
                //count the number of columns which unsorted
                c++;
            }
        }
        //return the number of columns which unsorted
        return c;
    }
};
