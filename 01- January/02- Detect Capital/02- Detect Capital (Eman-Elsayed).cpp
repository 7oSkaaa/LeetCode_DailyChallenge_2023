// Author : Eman Elsayed

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        // create vector to store Captiol charater indices
        vector<int> Idx;
        // loop on characters Word string and push their Capital charater indices
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                Idx.push_back(i);
            }
        }
        // here i'm checking if All letters in this word are not capitals
        // All letters in this word are capitals or Only the first letter in this word is capita
        return Idx.size() == 0 || Idx.size() == word.size() || (Idx.size() == 1 and Idx[0] == 0);
    }
};
