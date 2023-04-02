//Author: Sara Hamza

class Solution {
public:

    int compress(vector<char>& chars) {
        int  n = chars.size();
        int freq[2009] = {0};

        // construct freq:
        //  for each substring, save its size in freq[idx]
        //  where idx is the starting index of this substring
        freq[0]++;
        int idx = 0;
        for(int  i = 1; i < n; ++i) {
            if(chars[i] == chars[i - 1])
                freq[idx]++;
            else
                freq[i]++, idx = i;
        }

        // reconstruct chars vector:
        int itr = 0;
        for(int  i = 0; i < n; ++i) {
            // i is not the start of the substring => skip
            if(!freq[i])
                continue;

            // save the starting char
            chars[itr++] = chars[i];

            // save the size of this substring if it is > 1
            if(freq[i] > 1) {
                string num = to_string(freq[i]);
                for(auto k : num)
                    chars[itr++] = k;
            }

        }

        // at the end itr is the size of the new vector
        chars.resize(itr);

        return itr;

    }
};
