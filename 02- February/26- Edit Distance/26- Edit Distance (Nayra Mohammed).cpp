// Author: Nayra Mohammed 

#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))

int dp[500][500];//for memoization

class Solution
{
public:
    /*
        - To make word1 equal to word2, we have the following options for string word1:
                                            * Replace a specific character
                                            * Delete a specific character
                                            * Insert a character in any desired position
   
        - Using Dp with two states (i"current word1's index",j "current word2's index").
        For each word2's index, if current character it faces in word1 equals to it then we move to the next index in both of them with cost = 0.
        Otherwise,we need to do an operation to word1:
            * we can replace current facing character from word1 with similar character of word2's and move to next index in both of them
            * we can delete word1's current character and processed to next index in word1      
            * we can insert a new character similar to word2's in current position "shifting current character to index+1"and move to next index in word2 
        All of these operation will have a cost = 1

        - In any current state we take the minimum cost we can do from it till reaching our base state! 
    */

    int Min_Cost(int i, int j, string &x, string &y)
    {
        //if we finished matching all word2's character and still word1 didn't reach it's limit then we delete them with cost equals to their count ,otherwise 0
        if (j == sz(y))  
            return max(sz(x) - i, 0);

        if (i == sz(x)) //word1's index reached its limit and we still need to find the rest of word2 then we insert characters to word1 equal to the remaining characters with cost equals to their count
            return sz(y) - j;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (x[i] == y[j])//current character from word1 equals to word2's then no operation is needed and we move to next character in both of them
            return dp[i][j] = Min_Cost(i + 1, j + 1, x, y);

        //Otherwise, we need to perform operation in word1 with cost = 1 as we discussed above, so we take the minimum one of them
        return dp[i][j] = 1 + min({Min_Cost(i + 1, j, x, y), Min_Cost(i, j + 1, x, y), Min_Cost(i + 1, j + 1, x, y)});
    }
  
    int minDistance(string word1, string word2)
    {
        MemS(dp, -1);
        return Min_Cost(0, 0, word1, word2);
    }
};
