// Author: Mina Magdy

class DSU {
    public:
    vector<int> p;
    DSU(int n = 26) {
	// Initialize the parent vector
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int ascii(char c) {
        return c - 'a';
    }
    int find(char c) {
        return find(ascii(c));
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void merge(char u, char v) {
	/*
	 * 
	 * When merging ... get the parent of both characters and make the smallest one be the parent of all
	 * It guarantees that the parent will be the smallest character in each group
	 *
	 */
        
	int r1 = find(u), r2 = find(v);
        if (r1 < r2) {
            p[r2] = r1;
        }
        else {
            p[r1] = r2;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
	    // Merge each character in s1 to its corresponding character in s2
            dsu.merge(s1[i], s2[i]);
        }
        string ans;
        for (int i = 0; i < int(baseStr.size()); i++) {
	    /*
	     *
	     * Take the parent of the group for each character in baseStr
	     * It guarantees that it will be the lexicographically smallest string
	     *
	     */
            ans += 'a' + dsu.find(baseStr[i]);
        }
        return ans;
    }
};
