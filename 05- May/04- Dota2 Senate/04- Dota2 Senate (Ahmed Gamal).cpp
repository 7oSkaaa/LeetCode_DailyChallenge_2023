// Author: Ahmed Gamal

// for this problem we will use a greedy approach to choose the next senator to ban
// it can be proven that if we choose the next senator to ban greedily we will get the optimal answer (you can look at the proof in the editorial)
// first we will count the number of R and D senators
// second we will loop over the senate string circularly and for each senator we will check if there is an active senator from the other party
// if there is an active senator from the other party we will ban the current senator and decrease the number of senators from his party by one
// if there is no active senator from the other party we will make the current senator active and increase the number of active senators from his party by one
// we will continue this process until one of the parties has no senators left


class Solution {
public:
    string predictPartyVictory(string senate) {
        // n: number of senators
        // total_r: number of R senators
        // total_d: number of D senators
        // active_r: number of active R senators
        // active_d: number of active D senators
        // vis: array to mark the senators that are banned
        const int n = int(senate.size());
        int total_r = 0, total_d = 0;
        int active_r = 0, active_d = 0;
        vector<bool> vis(n);

        // count the number of R and D senators
        for(auto& i : senate) {
            total_r += i == 'R';
            total_d += i == 'D';
        }

        // loop over the senate string circularly (until one of the parties has no senators left)
        for(int i = 0; total_r and total_d; i = (i + 1) % n) {
            // if the current senator is banned we will continue
            if(vis[i]) {
                continue;
            }

            // if the current senator is from the R party
            if(senate[i] == 'R') {
                // if there is an active senator from the D party we will ban the current senator and decrease the number of senators from his party by one
                if(active_d) {
                    vis[i] = true;
                    active_d--;
                    total_r--;
                } else {
                    // if there is no active senator from the D party we will make the current senator active and increase the number of active senators from his party by one
                    active_r++;
                }
            } else {
                // if there is an active senator from the R party we will ban the current senator and decrease the number of senators from his party by one
                if(active_r) {
                    vis[i] = true;
                    active_r--;
                    total_d--;
                } else {
                    // if there is no active senator from the R party we will make the current senator active and increase the number of active senators from his party by one
                    active_d++;
                }
            }
        }

        // return the winner
        return total_r ? "Radiant" : "Dire";
    }
};