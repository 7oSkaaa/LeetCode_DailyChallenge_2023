// Author: Ahmed Hossam

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        // the frequency of each level
        unordered_map < int, int > freq;

        // make frequency array of tasks -> using map because number in range 10^9
        for(auto& task : tasks)
            freq[task]++;

        // the rounds it takes to complete the tasks
        int rounds = 0;

        // iterate over the map l -> level, f -> frequency of the level
        for(auto& [l, f] : freq){
            // if f = 1 so we can do the missions so will return -1
            if(f == 1)
                return -1;

            // rounds += ceil(f / 3)
            rounds += ((f + 2) / 3);
        }

        // the minimum rounds;
        return rounds;
    }
};
