// Author: Noura Algohary

class Solution {
public:
// comparison condition to sort in descending order
static bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}
vector<pair<int, int> > sortMap(map<int, int> map)
{
    // Declare vector of pairs
    vector<pair<int, int> > orderedMap;
 
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        orderedMap.push_back(it);
    }
 
    // Sort using comparator function
    sort(orderedMap.begin(), orderedMap.end(), cmp);

    return orderedMap;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
     map<int, int>map;  // original frequency map
     vector<pair<int, int> > orderedMap;
     vector<int>answer;

     for(int num : nums)
     {
        if(map.count(num))
            map[num]++;
        else 
            map.insert({num, 1});
     }   
     
    // store ordered map in a vector of pairs
    orderedMap = sortMap(map);

    for(auto it=orderedMap.begin(); k > 0 ;it++)
    {
        answer.push_back(it->first);
        k--;
    }

     return answer;
    }
};