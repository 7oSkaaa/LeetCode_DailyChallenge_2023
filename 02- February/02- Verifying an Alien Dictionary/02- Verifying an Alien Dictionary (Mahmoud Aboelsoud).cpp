// Author: Mahmoud Aboelsoud

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // we first map the order to the alphabet
        // so if we have an order like "hlabcdefgijkmnopqrstuvwxyz" we map it to "abcdefghijklmnopqrstuvwxyz"
        // then we map each letter in the words to the letter it maps to in the alphabet
        // so if we have a word like "hello" we map it to "agbbo"
        // then we check if the words are sorted or not
        // if they are sorted then we return true
        // else we return false


        // we map the order to the alphabet
        unordered_map<char,char> ma;
        int j = 0;
        for(auto i = 'a'; i <= 'z'; i++, j++)
            ma[order[j]] = i;

        // we map each letter in the words to the letter it maps to in the alphabet
        for(int i = 0; i < words.size(); i++){
            for(auto&j: words[i])
                j = ma[j];
            
            // we check if the words are sorted or not
            if(i)
                // if they are not sorted then we return false
                if(words[i] < words[i - 1]) return 0;
        }

        // if they are sorted then we return true
        return 1;
    }
};
