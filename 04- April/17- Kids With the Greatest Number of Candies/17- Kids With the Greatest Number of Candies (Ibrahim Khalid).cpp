// Author : Ibrahim Khalid
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // store result
        vector<bool>res;
        int n=candies.size();
        // to store max element of candies(vector) to compare with other elementer plus  value 's  extraCandies
        int mx=*max_element(candies.begin(),candies.end());
        for(int i=0;i<n;i++){
            //to compare the max with other elementer plus  value 's  extraCandies
            if((candies[i]+extraCandies)>=mx){
                res.push_back(true);
            }
            else{
                res.push_back(false);

            }
        }
        return res;
    }
};