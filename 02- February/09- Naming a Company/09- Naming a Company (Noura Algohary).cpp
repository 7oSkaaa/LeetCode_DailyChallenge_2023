// Author: Noura Algohary
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>suffixes[26]; // to group names by their first char
        long long total_cnt = 0, mutual_cnt = 0;

        for(string idea: ideas)
        {
            suffixes[idea[0] - 'a'].insert(idea.substr(1)); // assign all the strings(withour first letter) to the first letter group
        }

        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                // counting mutual names produced by concatenating strings from 1 group to the other letter of a second group
                mutual_cnt = 0;
                for(string suffix : suffixes[i])
                {
                    if(suffixes[j].count(suffix))
                        ++mutual_cnt;
                }
                total_cnt += 2 * (suffixes[i].size() - mutual_cnt) * (suffixes[j].size() - mutual_cnt);
            }
        }
        return total_cnt;
    }
};