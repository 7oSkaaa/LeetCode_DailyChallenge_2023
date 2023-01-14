//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))

class Solution {
public:

    int mn[26]; // for each character we save the minimum character it can be reached through it
    vector<set<int>>v; // adjacency list using set to avoid unwanted duplicated childs
    
    void add_edge(char x,char y){ //make undirected edge in our graph
        v[x -'a'].insert(y -'a'); // we subtract from character 'a' to get its order alphabetically for simplicity
        v[y -'a'].insert(x -'a');
    }

    int Dfs(int st,int pr,int mnn){
        mn[st] = min(st,mnn) ; //take the minimum between current node 'st' and the minimum character that was passed through current subtree 

        for(auto ch:v[st])
            if(ch != pr && mn[ch] == -1)//avoid cyclic traverse
                mn[st] = min(mn[st], Dfs(ch,st,mn[st])); //traverse through each child and minimize answer for current node and the returned value

        return  mn[st];  //return  node's minimum character that can be reached  through it     
    }

    

    string smallestEquivalentString(string s1, string s2, string baseStr) {
      
        string ans = "";//store our answer
        MemS(mn,-1);//set all mn values for each characters equal to -1 (to know whether we visited it or not)
      
        v.resize(26);
       
        for(int i = 0; i < sz(s1); i++)
            add_edge(s1[i], s2[i]); //for each pair of equivalent characters we simulate it into our graph to each the idea of "Transitivity"

       /* 
          we iterate from 'a' to 'z' to assure that we can take minimum value through our connected componenet starting from current node reachin' its childs
          in worst case.
          
          test: s1= "zzc",s2 = "bca",baseStr="bzczz"  ---> ans = "aaaaa"
          iterating through alphabetic in a random way would result a wrong answer.
          
       */
        for(int i = 0 ;i < 26;i++)  
            if(mn[i] == -1)//   find the smallest character can be reached through node i in other words character (i +'a') if it wasn't visited before
              Dfs(i, i, i);

        for(auto it:baseStr)
            ans += (mn[it - 'a'] + 'a'); //add the minimum reached character for current baseStr's character (adding 'a' to make it in its normal form of charcters)       
        
        return ans;
    }
};
