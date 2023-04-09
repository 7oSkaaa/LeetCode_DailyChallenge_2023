// Author: Mahmoud Aboelsoud

class Solution {
public:
    int partitionString(string s) {
        // we need to find the minimum number of partitions that we can make ot make each substring have unique characters
        // we can use a map to store the number of occurences of each character
        // if we find a character that has already been seen, we need to make a partition
        // we can clear the map and start counting again

        // cnt: number of partitions
        int cnt = 0;
        // ma: map to store the number of occurences of each character
        unordered_map<char,int> ma;

        // loop over the string
        for(auto&i: s){
            // increase the number of occurences of the current character
            ma[i]++;
            // if the current character has been seen before, we need to make a partition
            if(ma[i] > 1){
                // increase the number of partitions
                cnt++;
                // clear the map
                ma.clear();
                // add the current character to the map
                ma[i]++;
            }
        }

        // return the number of partitions + 1 (the last partition)
        return cnt + 1;
    }
};
