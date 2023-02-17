//Author: Mohamed Ibrahim

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // create a hash map to store the order of the characters
        unordered_map<char, int> hash;
        for (int i = 0; i < order.size(); i++) {
            // map each character to its corresponding index in the order string
            hash[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            // compare two consecutive words in the vector
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            for (int j = 0; j < len; j++) {
                // if the characters at the same position of two words have different order
                if (hash[word1[j]] < hash[word2[j]]) {
                    // the words are sorted
                    break;
                } else if (hash[word1[j]] > hash[word2[j]]) {
                    // the words are not sorted
                    return 0;
                } else {
                    // if they have the same order, move to the next character
                    if (j == len - 1 && word1.size() > word2.size()) {
                        // if one word is a prefix of another word and the prefix is larger than the other word, the words are not sorted
                        return 0;
                    }
                }
            }
        }
        // if all the comparisons return true, the words are sorted
        return 1;
    }
};
