// Author : Nayra Mohammed

#define sz(s) (int(s.size()))
// 4 negihbours
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

/*
    - Main Idea : Multi-Source BFS
    - As we need to find the distance between every water cell and nearest land cells for them
    So, Considering all lands as our sources ,we gonna traverse through them to their neighbours "above , below,left and right the land cell" Using BFS
    And for each water cell we reach, we maximize our answer with the number of steps we consumed till reaching current cell and so on till we finish visiting all n*n cells
*/

class Solution
{
public:
    int vis[100][100]; // to store for each cell the number of steps we consumed till reaching it + avoid infinite traverse in bfs

    struct Point
    {
        int x, y;
    };

    queue<Point> q; // to traverse through our grid level by level "BFS"

    bool valid(int x, int y, int r, int c) // to check whether we are going into a valid unvisited cell or not
    {
        return x >= 0 && x < r && y >= 0 && y < c && !vis[x][y];
    }

    int BFS(vector<vector<int>> &v)
    {
        int mx = 0; // to store the maximum distance between water cell and its nearst land cell

        Point st;

        while (sz(q))
        {
            st = q.front(), q.pop();

            if (!v[st.x][st.y]) // if we are currently in a water cell ,update the answer
                mx = max(mx, vis[st.x][st.y]);

            for (int i = 0; i < 4; i++) // visit all neighbours of our current cell
                if (valid(st.x + dx[i], st.y + dy[i], sz(v), sz(v[0]))) // if valid then push into our queue as our next level and update the number of steps for them
                    q.push({st.x + dx[i], st.y + dy[i]}), vis[st.x + dx[i]][st.y + dy[i]] = vis[st.x][st.y] + 1;
        }

        return mx - 1; // we decrease our answer by 1 due to the additional one in our base sources' steps
    }

    int maxDistance(vector<vector<int>> &vv)
    {
        for (int i = 0; i < sz(vv); i++)
            for (int j = 0; j < sz(vv[i]); j++)
                if (vv[i][j]) // we consider all lands as our sources, we push them into our queue as our first level
                    q.push({i, j}), vis[i][j] = 1; // mark current cell as visited with initially 1

        return BFS(vv);
    }
};
