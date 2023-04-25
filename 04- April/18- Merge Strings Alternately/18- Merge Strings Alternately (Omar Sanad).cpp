// author : Omar Sanad
class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        // declaring the answer string which we will return
        string ans;

        // declaring a boolean variable which controls the turns between the two strings
        bool turn = true;

        // declaring two pointers i -> word1,  j -> word2
        int i = 0, j = 0;

        // two pointers while loop
        // we loop while one string at least still have characters
        while (i < word1.size() or j < word2.size()) {

            // if the string word2 is out of characters
            // or the string word1 still have characters and it is its turn
            // then we take a character from word1
            if (j >= word2.size() or (i < word1.size() and turn))
                ans.push_back(word1[i++]), turn = false;
            
            // else we take a character from word2
            else
                ans.push_back(word2[j++]), turn = true;
        }


        // return the answer
        return ans;
    }
};
