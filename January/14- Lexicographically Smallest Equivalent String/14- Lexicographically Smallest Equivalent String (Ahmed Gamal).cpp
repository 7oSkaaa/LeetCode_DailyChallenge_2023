// Author: Ahmed Gamal


class Solution {
public:

    // we want to group the characters from the two strings s1 and s2 so that the characters in each group are equivalent (the three properties applies)
    // reflexive: a is equivalent to a (a is in the same group as a)
    // symmetric: if a is equivalent to b, then b is equivalent to a (if a is in the same group as b, then b is in the same group as a)
    // transitive: if a is equivalent to b and b is equivalent to c, then a is equivalent to c (if a is in the same group as b and b is in the same group as c, then a is in the same group as c)
    // to find the equivelance of characters, we can use a DSU (Disjoint Set Union) data structure
    // we can use a DSU (Disjoint Set Union) data structure to group the characters (if we joined two characters, then they are in the same group, and if they are in the same group, then they are equivalent)
    // once we constructed the groups, we can find the smallest character in each group and use it to construct the answer
    // we can store the whole group in a list, and we can use the list to find the smallest character in the group in O(1) time (after sorting the list)
    // or we can store one vector and for each leader of a group, we can store the smallest character in it (alternative implementation)

    // we are going to use list to store groups because lists are faster than vectors and sets in joining one group to another
    // it just do it in O(1) time, and it doesn't need to sort the group after joining it to another group


    // DSU data structure
    struct dsu{
        // p: the parent of each group (leader of each group)
        // rank: the rank of each leader (to decide which leader will be the parent of the other leader)
        vector<int> p, rank;
        // sets: the groups
        vector<list<int>> sets;
    
        // constructor
        dsu(int size){
            p.resize(size + 1);
            rank.resize(size + 1);
            sets.assign(size + 1, list<int>());

            // initialize the groups with one character in each group (each character is in a group with itself)
            for(int i = 0; i < size; i++){
                sets[i].emplace_back(i);
            }
    
            // initialize the parent of each group to be the group itself
            iota(p.begin(), p.end(), 0);
        }
    
        // get the leader of the group that the character x is in
        int get(int x){
            return p[x] = x == p[x] ? x : get(p[x]);
        }
    
        // join the groups that the characters u and v are in
        void join(int u, int v){
            // get the leaders of the groups that the characters u and v are in
            u = get(u), v = get(v);
    
            // if they are in the same group, then return (they are already equivalent)
            if(u == v)
                return;
    
            // if the rank of leaders of the groups that the characters u and v are in is the same, then increase the rank of the leader of the group that the character u is in (to make it the parent of the other leader)
            if(rank[u] == rank[v])
                rank[u]++;
    
            // if the rank of the leader of the group that the character u is in is greater than the rank of the leader of the group that the character v is in, then make the leader of the group that the character v is in the parent of the leader of the group that the character u is in
            // join the group that the character v is in to the group that the character u is in (move all the characters in the group that the character v is in to the group that the character u is in)
            // we can use splice to join the groups in O(1) time
            if(rank[u] > rank[v]) {
                p[v] = u;
                sets[u].splice(sets[u].end(), sets[v]);
            }else {
                // if the rank of the leader of the group that the character v is in is greater than the rank of the leader of the group that the character u is in, then make the leader of the group that the character u is in the parent of the leader of the group that the character v is in
                // join the group that the character u is in to the group that the character v is in (move all the characters in the group that the character u is in to the group that the character v is in)
                // we can use splice to join the groups in O(1) time
                p[u] = v;
                sets[v].splice(sets[v].end(), sets[u]);
            }
        }
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // construct the DSU data structure
        // the size of the DSU data structure is 26 because we have 26 characters
        dsu d(26);

        // join the groups of the characters in the two strings s1 and s2
        for(int i = 0; i < s1.size(); i++){
            int u = s1[i] - 'a', v = s2[i] - 'a';
            d.join(u, v);
        }

        // sort the groups (to find the smallest character in each group in O(1) time)
        auto& sets = d.sets;
        for_each(sets.begin(), sets.end(), [&](list<int>& x) -> void {
            x.sort();
        });

        // construct the answer
        string ans;
        // for each character in the string baseStr, find the smallest character in the group that the character is in
        for(auto& i : baseStr){
            ans += char(sets[d.get(i - 'a')].front() + 'a');
        }

        // return the answer
        return ans;
    }
};