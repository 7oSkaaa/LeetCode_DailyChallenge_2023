// Author: Mahmoud Aboelsoud

class Solution {
public:
    // Disjoint Set Union (DSU) data structure

    vector<int> parent, set_size;

    int find_set(int v){
        if(v == parent[v]) return v;

        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(set_size[a] < set_size[b])
                swap(a, b);
            parent[b] = a;
            set_size[a] += set_size[b];
        }
    }

    bool same_set(int a, int b){
        a = find_set(a);
        b = find_set(b);

        return a == b;
    }

    // in this problem we need to know how many similar groups are there
    // we can do that by brute force and check each pair of strings if they are similar or not
    // and if they are similar we can merge them in the same group which will help us to know the number of groups at the end
    

    int numSimilarGroups(vector<string>& strs) {
        // n: number of strings
        int n = strs.size();
        // parent: parent of each string
        parent.assign(n, 0);
        // set_size: size of each set
        set_size.assign(n, 1);

        // initially each string is in its own set (group) and its parent is itself
        for(int i = 0; i < n; i++)
            parent[i] = i;

        
        // we can check each pair of strings if they are similar or not and merge them in the same group if they are similar
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // if they are not in the same group then we check if they are similar or not
                if(!same_set(i, j)){
                    // cnt: number of different characters between the two strings
                    int cnt = 0;
                    // loop over the two strings and count the number of different characters and add a condition to break the loop if the number of different characters is more than 2
                    // because if the number of different characters is more than 2 then the two strings are not similar and we don't need to check the rest of the characters
                    for(int k = 0; k < strs[i].size() && cnt <= 2; k++)
                        cnt += (strs[i][k] != strs[j][k]);

                    // if the number of different characters is 0 or 2 then the two strings are similar and we merge them in the same group
                    if(cnt == 0 || cnt == 2) union_sets(i, j);
                }
            }
        }

        // st: set of parents of all strings
        set<int> st;
        
        // loop over all strings and insert their parents in the set
        for(int i = 0; i < n ; i++)
            st.insert(find_set(i));

        // return the size of the set which is the number of groups
        return st.size();
    }
};
