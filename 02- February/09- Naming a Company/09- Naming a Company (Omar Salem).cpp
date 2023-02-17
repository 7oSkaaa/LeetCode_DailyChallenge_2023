//Author: Omar Salem
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector < unordered_set<string> > group(26);
        // Make group of first letter for each element of ideas
        // [{c -> offee }, {d -> onuts} ,{t -> ime , t-> offee}]
        for(auto &i : ideas)
             group[i[0] - 'a'].insert(i.substr(1));
        //initilize varible
        long long numOfNames = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                int numOfSuffixes = 0;
                // count the same suffixes of group A
                    for (auto &idea : group[i])
                     numOfSuffixes += group[j].count(idea);
                // we can calculate Number of valid Name -> sizeOf(groupA) * sizeOf(groupB)*2 if each group have distinct valid names
                // else we can Subtraction same suffixes for each group
                numOfNames += 2LL * (group[i].size() - numOfSuffixes) * (group[j].size() - numOfSuffixes);
            }
        }

        return numOfNames;
    
    }
};