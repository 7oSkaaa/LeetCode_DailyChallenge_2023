// Author: Ahmed Hossam

template < typename T = int, int Base = 0 > struct DSU {
    
    vector < T > parent;

    // every parent will be a char equal to it, 0 -> 'a', 1 -> 'b' and so on
    DSU(int MaxNodes){
        parent = vector < T > (MaxNodes + 5);
        for(int i = Base; i <= MaxNodes; i++)
          parent[i] = char(i + 'a');
    }

    // git the index of the char to acces the vector
    int fix(char c){
        return c - 'a';
    }

    // get the leader of each component
    T find_leader(char node){
        return parent[fix(node)] = (parent[fix(node)] == node ? node : find_leader(parent[fix(node)]));
    }

    // check if the two chars in the same set
    bool is_same_sets(char u, char v){
        return find_leader(u) == find_leader(v);
    }

    // union two component together and make the leader is the smallest character in the component
    void union_sets(char u, char v){
        char leader_u = find_leader(u), leader_v = find_leader(v);
        if(leader_u == leader_v) return;
        if(leader_u > leader_v) 
            swap(leader_u, leader_v);
        parent[fix(leader_v)] = leader_u;
    }

    // get the minimum character in component and it is the leader of the component
    char get_min(char c){
        return find_leader(c);
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // DSU with char type
        DSU < char > dsu(26);
        
        // number of character
        int n = s1.size();

        // union the two sets of the two characters together
        for(int i = 0; i < n; i++)
            dsu.union_sets(s1[i], s2[i]);

        // replace every char in baseStr with the minimum char of it's set
        for(auto& c : baseStr)
            c = dsu.get_min(c);

        // the minimum lexicographically baseStr
        return baseStr;      
    }
};
