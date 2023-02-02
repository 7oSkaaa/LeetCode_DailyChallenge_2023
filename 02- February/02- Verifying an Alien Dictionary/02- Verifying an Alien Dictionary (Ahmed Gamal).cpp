// Author: Ahmed Gamal


class Solution {
public:

    // in this problem we have to check if the words are sorted or not (according to the alien dictionary)
    // so we can sort the words according to the alien dictionary and then check if the sorted words are equal to the original words or not
    // so we can use the sort function and pass a lambda function to it to sort the words according to the alien dictionary
    // the lambda function will take two strings and return true if the first string is smaller than the second string
    // a string is smaller than another string if it has a smaller character in the same index or if it has a smaller length
    // so we can check if the smaller string is a prefix of the bigger string or not
    // if it is a prefix then the smaller string is the shorter one, and we just return true if it is equal to the first string
    // if it is not a prefix then we can loop on the smaller string and check if the characters are equal or not
    // if they are not equal then we can return true if the first character is smaller than the second character

    bool isAlienSorted(vector<string>& words, string order) {
        // copy the words to another vector to check if the words are sorted or not after sorting
        vector<string> cpy(words);

        // create a vector to store the new order of the characters
        vector<int> ord(26);
        for(int i = 0; i < order.size(); i++){
            ord[order[i] - 'a'] = i;
        }

        // sort the words according to the alien dictionary
        sort(words.begin(), words.end(), [&](string& a, string& b){
            string mx = max(a, b), mn = min(a, b);
            if(mx.substr(0, mn.size()) == mn)
                return a == mn;
            
            for(int i = 0; i < min(a.size(), b.size()); i++){
                if(a[i] != b[i])
                    return ord[a[i] - 'a'] < ord[b[i] - 'a'];
            }
            return true;
        });

        // check if the words are sorted or not
        return cpy == words;
    }
};