// Author: Ahmed Hossam

class Solution {
public:
    
    #define sz(x) int(x.size())

    long long distinctNames(vector<string>& ideas) {
        long long disName = 0;

        // adjacent list for each character
        vector < unordered_set < string > > adj(26);
        
        // add each string to the vector of each character
        for (string s : ideas) 
            adj[s[0] - 'a'].insert(s.substr(1));
        
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                // merge the two sets into one set
                unordered_set < string > unique;
                unique.insert(adj[i].begin(), adj[i].end());
                unique.insert(adj[j].begin(), adj[j].end());

                // update the disName
                disName += (sz(adj[i]) - sz(unique)) * (sz(adj[j]) - sz(unique));
            }
        }

        // the answer will be the double of disName
        return disName * 2;
    }
};
