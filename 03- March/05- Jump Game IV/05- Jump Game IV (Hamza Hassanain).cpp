// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;
/*
    Approach: run a BFS, keep track of the visited indecis and values
*/
class Solution
{
public:
    long long minJumps(vector<int> &arr)
    {
        unordered_map<int, vector<int>> similars; // store the value with all its indecies
        for (int i = 0; i < arr.size(); i++)
            similars[arr[i]].push_back(i);

        unordered_map<int, bool> visited;
        unordered_map<int, bool> usedValues; // keep track of the values added to our next to go inorder not to do it again
        queue<int> nextToGo;
        nextToGo.push(0);

        visited[0] = true;

        int jumps = 0;
        while (nextToGo.size())
        {
            int prevSize = nextToGo.size();
            while (prevSize--)
            {
                int cur = nextToGo.front();
                nextToGo.pop();

                if (cur == arr.size() - 1) // we reach the end then we are done
                    return jumps;

                // add the i+1 if not visisted
                if (!visited[cur + 1])
                    nextToGo.push(cur + 1), visited[cur + 1] = true;

                // add the i-1 if not -1 and not visisted
                if (cur && !visited[cur - 1])
                    nextToGo.push(cur - 1), visited[cur - 1] = true;

                if (usedValues[arr[cur]]) // if we used this value before this means we added all indecies with this value before then we do not have to do it again
                    continue;
                for (int idx : similars[arr[cur]])
                    if (!visited[idx])
                        nextToGo.push(idx), visited[idx] = true;

                usedValues[arr[cur]] = true;
            }
            jumps++;
        }

        return -1;
    }
};
