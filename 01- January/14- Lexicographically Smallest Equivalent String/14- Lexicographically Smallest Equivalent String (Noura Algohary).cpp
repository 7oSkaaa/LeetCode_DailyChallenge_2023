// Author: Noura Algohary
class Solution {
public:

    void dfs(int ch,  vector<vector<int>>& adjMat, set<int>& group, vector<bool>& visited)
    {
        visited[ch] = true;

        // add the char to the group of equevalent letters
        group.insert(ch);

        for(int i=0;i<26;i++)
        {
            if(adjMat[ch][i] && !visited[i])
            {
                dfs(i, adjMat, group, visited);
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string equivalent = ""; // equivalent string to baseStr

        vector<vector<int>> adjMat (26, vector<int>(26, 0));  // adjacency matrix 


        // first, impelement relation between each two letters into adjacency matrix
        int l1, l2, l;
        for(int i=0;i<s1.size();i++)
        {
            l1 = s1[i] - 'a';
            l2 = s2[i] - 'a';

            adjMat[l1][l2] = 1;
            adjMat[l2][l1] = 1;
        }

        // store the min char of each letter
        // begin with the char itself
        vector<int> eq(26, 0);
        for (int i = 0; i < 26; i++) {
            eq[i] = i;
        }

        vector<bool> visited (26, 0);
        set<int> group;   // group of related or equal letters

        for(int ch=0; ch<26; ch++)
        {
            if(!visited[ch])
            {
                dfs(ch, adjMat, group, visited);

                // assign the min char of the group as equivalent to the rest
                for(auto c : group)
                {
                    eq[c] = *group.begin();  // the first element in a set is the smallest as it is sorted in ascending order
                }

                group.clear();
            }


        }

            for(char ch : baseStr)
            {
                equivalent += char(eq[ch - 'a'] + 'a');  
            }

        return equivalent;
    }
};