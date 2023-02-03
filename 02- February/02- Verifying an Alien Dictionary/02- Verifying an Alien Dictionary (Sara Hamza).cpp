//Author: Sara Hamza

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        /*
        1. mapping their language to ours to compare

        2. check if it is sorted or not :

            2.1 Letter Check:

                Iterating the words at the same position of the letter for all letters:

                if the i-th letter of th current word ">" that of the previous?  => pass
                if              "                     "<"          "          ?  => return false
                if              "                     "="          "          ?  => "can't judge" check for the next letter

            2.2 Word Size Check:

                In case of running out of letters of some word while comparing,
                make sure that its length > the previous one's length
        */

        //mapping their language to ours
        unordered_map <char, char> mp;

        for(int i=0; i<26; ++i){
            mp[order[i]] = i+'a';
        }


        int m = (int)words.size();

        //size of the longest word
        int n = (int)words[0].size();

        for(int i=1; i<m; ++i){
            if(words[i].size() > n)
                n = words[i].size();
        }

        for(int i=0; i<n; ++i){
            char prev = 'a'-1;
            bool equal = 0;

            //check at the i-th position of words
            for(int j=0; j<m; ++j){
                //size check
                if(i >= words[j].size()) {
                    if(j != 0 && words[j].size() < words[j-1].size())
                        return false;
                    continue;
                }

                //letter check
                if(mp[words[j][i]] > prev){
                    prev = mp[words[j][i]];
                }
                else if(mp[words[j][i]] == prev){
                    equal = 1;
                }
                else{
                    return false;
                }
            }

            if(!equal) // it is definitely " > prev " case
                return true;

        }
        return true;
    }
};
