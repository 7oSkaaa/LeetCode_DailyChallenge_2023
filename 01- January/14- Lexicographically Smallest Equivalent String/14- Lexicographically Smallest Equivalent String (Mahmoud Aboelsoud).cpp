// Author: Mahmoud Aboelsoud


// DSU data data structure to store the groups of equivalent characters
struct DSU{
    // initialize parent vector to store the parent of each character, set_size to store the size of each group and smallest_in_group to store the smallest character in each group
    vector<int> parent, set_size, smallest_in_group;

    // constructor to initialize our vectors with each character as it's own parent and size 1 and smallest character as itself
    DSU(int n){
        parent.assign(n, 0);
        set_size.assign(n, 1);
        smallest_in_group.assign(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i, smallest_in_group[i] = i;
    }

    // find_set function to find the parent of a character
    int find_set(int v){
        if(v == parent[v]) return v;

        return parent[v] = find_set(parent[v]);
    }


    // union_sets function to merge two groups
    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(set_size[a] < set_size[b])
                swap(a, b);
            parent[b] = a;
            set_size[a] += set_size[b];
            // update the smallest character in the group with the smallest character in the two merged groups
            smallest_in_group[a] = min(smallest_in_group[a], smallest_in_group[b]);
        }
    }

};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // initialize our DSU data structure
        DSU dsu(26);
        int n = s1.size();

        // merge each character in s1 to its corresponding character in s2
        for(int i = 0; i < n; i++)
            dsu.union_sets((s1[i] - 'a'), (s2[i] - 'a'));
        
        // initialize our answer string
        string ans = "";
        
        for(int i = 0; i < baseStr.size(); i++){
            // get the smallest character in the group of the current character in baseStr
            int x = dsu.smallest_in_group[dsu.find_set(baseStr[i] - 'a')];
            // add it to our answer string
            ans += char(x + 'a');
        }

        return ans;

    }
};
