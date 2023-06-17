// Author: Ahmed Hossam

constexpr int N = 2005, INF = 2e9;
int dp[N][N][2], vis[N][N][2], n, m, id;
vector < int > a, b;
bool is_memed = false;

class Solution {
public:

    int min_moves(int a_idx, int b_idx, bool is_a_last){
        if(a_idx == n) return 0;
        int& ret = dp[a_idx][b_idx][is_a_last];
        if(vis[a_idx][b_idx][is_a_last] == id)
            return ret;
        vis[a_idx][b_idx][is_a_last] = id;
        ret = INF;
        int last_num = is_a_last ? a[a_idx - 1] : b[b_idx - 1];
        if(a[a_idx] > last_num)
            ret = min(ret, min_moves(a_idx + 1, b_idx, true));
        int idx = upper_bound(b.begin(), b.end(), last_num) - b.begin();
        if(idx != m)
            ret = min(ret, 1 + min_moves(a_idx + 1, idx + 1, false));
        return ret;
    }

    Solution(){
        id++;
        if(!is_memed){
            memset(dp, -1, sizeof(dp));
            memset(dp, -1, sizeof(vis));
            is_memed = true;
        }
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        a = arr1, b = arr2;
        n = a.size(), m = b.size();
        int best_moves = min(min_moves(1, 0, true), 1 + min_moves(1, 1, false));
        if(best_moves >= INF)
            best_moves = -1;
        return best_moves;
    }
};
