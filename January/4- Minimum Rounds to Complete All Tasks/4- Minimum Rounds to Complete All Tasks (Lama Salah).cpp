// Author : Lama Salah

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // Create a map to store the frequencies of each number that appeared in the array:
        map <int, int> Frq;
        for(auto &i : tasks)
            Frq[i]++;

        int ans = 0;
        // Iterate over the map : l -> level, f -> frequency of the level:
        for (auto& [l, f] : Frq){
            // If the frequency of i is equal to one, then the answer will be -1 :
            if (f == 1) return -1;
            
            // Calculate the number of rounds with the maximum tasks first, and in this problem, the maximum number of tasks in a round is three.
            int rounds = f / 3;

            // If the frequency of any number is an odd number, and the rounds with three tasks are even:
            if ((f & 1) && !(rounds & 1)) rounds--;
            // If the frequency of any number is an even number, and the rounds with three tasks are odd:
            if (!(f & 1) && (rounds & 1)) rounds--;

            // Add the rounds to the answer and subtract all tasks in the rounds from the frequency of i:
            ans += rounds, f -= rounds * 3;

            // Calculate the rounds with two tasks:
            ans += f/2, f -= (f/2) * 2;
        }

        return ans;
    }
};