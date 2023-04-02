// author: ahamd abdelwhab
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //sorting the array
        sort(potions.begin() , potions.end());
        vector<int> answer;
        for(auto x :  spells)
        {
            long long number = ceil(success / (double)x); // getting the possible values that satisfies the relation
            //binary searching the possible indexes
            int pairs = distance(lower_bound(potions.begin() , potions.end() , number)  , potions.end());
            //pushing the answer into a answer vector
            answer.push_back(pairs);
        }
        return answer;
    }
};
