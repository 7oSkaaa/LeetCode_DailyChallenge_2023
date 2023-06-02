// Author: Emad Mohamed
/*
    Bomb1 makes bomb2 explode if the centre of bomb2 is 
    inside the blast radius (circle) of bomb1.
    First we can check every bomb i with bomb j to see
    which one makes the other explode (one way).
    And then we can try and start the explosion from every bomb using dfs.
    This will fit the time limit because n = 100
*/
class Solution {
    bool is_intersect(vector<int>& bomb1, vector<int>& bomb2){
        // use ll to avoid overflow
        long long x1 = bomb1[0], x2 = bomb2[0], y1 = bomb1[1], y2 = bomb2[1];
        // Distance between two centres
        double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        // If the distance between the 2 centres is <= the radius of the first bomb
        // then the first bomb will make the second explode
        return dist <= bomb1[2];
    }
    int dfs(int u, vector<vector<int>>& links, vector<bool>& vis){
        // If the bomb already exploded return 0
        if(vis[u])
            return 0;
        vis[u] = 1;
        int ret = 1;
        // Add the current bomb to the sum and check all the bombs in it's radius
        // that have not exploded yet
        for(auto &v : links[u])
            ret += dfs(v, links, vis);
        return ret;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>links(n);
        // If bomb i makes bomb j explode then link them together
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j && is_intersect(bombs[i], bombs[j]))
                    links[i].push_back(j);
        int ans = 0;
        for(int i = 0; i < n; i++){
            // Try and start the explosion from every bomb and maximize the answer
            vector<bool>vis(n);
            ans = max(ans, dfs(i, links, vis));
        }
        return ans;
    }
};
