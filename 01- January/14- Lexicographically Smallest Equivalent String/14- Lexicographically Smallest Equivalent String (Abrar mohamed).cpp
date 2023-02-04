// Author: Abrar Mohamed

class Solution {
public:
    vector<int> N;

    string smallestEquivalentString(string s1, string s2, string baseStr) {
//the characters are 26, so it will be its size
        N.resize(26);
        for (int i = 0; i < 26; ++i)
            N[i] = i;
        for (int i = 0; i < s1.size(); ++i) {
            int a = s1[i] - 'a', b = s2[i] - 'a';
            int Na = find(a), Nb = find(b);
            if (Na < Nb)
                N[Nb] = Na;
            else
                N[Na] = Nb;
        }
        string prob = "";
        for (char a : baseStr) {
//locate the smallest char of the group
            char b = (char)(find(a - 'a') + 'a');
            prob += b;
        }
        return prob;
    }

    int find(int x) {
        if (N[x] != x)
            N[x] = find(N[x]);
        return N[x];
    }
};