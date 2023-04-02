// Author: Zeinab Mohy

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //create vector to keep number which need to search
        vector<double>ser;
        /* create a copy of vector spells but in double datatype
         to get ceil answer from operation */
        vector<double>  spells_copied;
        spells_copied.assign(spells.begin(),spells.end());
        //vector to keep answers
        vector<int>return_ans;
        /* get ceil answer for each number in spells to get the minimum number 
          can be allowed */
        for(int i=0;i<spells_copied.size();i++){
            double serr=ceil(success/spells_copied[i]);
            ser.push_back(serr);//2 7 3
        }
        // sort potions vector to can apply the binary search technique correctly
        sort(potions.begin(),potions.end());
        /* get index which lower bound for each index which can be consider successful
          by getting the minimum which means all the indexes greater than the lower bound 
          is also successful */
        for(int i=0;i<ser.size();i++){
            int ans=lower_bound(potions.begin(), potions.end(), ser[i])
            - potions.begin();
            return_ans.push_back(potions.size()-ans);
        }
        return return_ans;
    }
};
