//Author :  Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{
public:
    //frq -> to store the frequencies of valid string starting with char j+'a' incase we replace it's first starting character with i +'a'
    int frq[26][26];  
    long long distinctNames(vector<string> &ideas)
    {

        unordered_set<string> s; //to store unique characters and search for their existence in O(1)as an average
        long long ans = 0; // to store our answer
        
        for (auto it : ideas) //insert each string into our set
            s.insert(it);

        for (char i = 'a'; i <= 'z'; i++)//for every possible starting characters
            for (auto it : s) // we check for each string whether replacing its starting character with i will produce a new string
                if (s.find(i + it.substr(1)) == s.end())
                    frq[i - 'a'][it[0] - 'a']++; // if so, we increase the frequency of that new starting character with the old one

        /*
        - Here we gonna iterate over all possible replacements between starting characters
        - The possibility of valid naming using string  starting with (i +'a') and string starting with (j+'a')
          is the frequency of all valid replacements between i,j multiplied by the frequency of all vlid replacements between j,i 
        */
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                ans += (frq[i][j] * frq[j][i]);

        return ans; //return the required answer
    }
};
