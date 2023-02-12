// author : Eman Elsayed

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        int n = ideas.size();

        vector<unordered_set<string>> v(26);
        /*
         what do we need to do?
         ideas = ["coffee","donuts","time","toffee"]
         divide the strings into 26 vectors and each vector contains the strings that start with the same character
         c: ["offee"]
         d: ["onuts"]
         t: ["ime","offee"]
         we don't need the strings that have the same suffix (e.g. "toffee" and "coffee" have the same suffix "offee")
         iterate over the vectors and count the number of strings that have the same suffix and remove them from calculation
         the correct strings are:
            c: ["offee"] and d: ["onuts"]  -> 2 * (1 * 1)
            c: ["offee"] and t: ["ime"]    -> 2 * (1 * 1)
            d: ["onuts"] and t: ["ime"]    -> 2 * (1 * 1)
            so the answer is 6
        */
        for (int i = 0; i < n; i++)
        {
            v[ideas[i][0] - 'a'].insert(ideas[i].substr(1));
        }
        long long ans = 0;
        for (int i = 0; i < 26; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                int cnt = 0;
                for (auto &k : v[i])
                {
                    cnt += v[j].count(k);
                }
                ans += 2LL * ((v[i].size() - cnt) * (v[j].size() - cnt));
            }
        }
        return ans;
    }
};