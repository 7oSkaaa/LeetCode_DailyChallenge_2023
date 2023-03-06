// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the minimum number of jumps to reach the last index
    // to do that we use BFS to find the shortest path from the first index to the last index
    // we use a map to store the indices of the same value in the array
    // at the current index we can jump to the index - 1, index + 1, and all the indices of the same value so 
    // each time we check if the index - 1 is valid and not visited before and we push it to the queue
    // each time we check if the index + 1 is valid and not visited before and we push it to the queue
    // each time we check if the index is in the map and we push all the indices of the same value to the queue
    // we also mark the current index as visited
    // we also check if the current index is the last index and we return the number of jumps if it is




    int minJumps(vector<int>& arr) {
        // if the array has only one element we don't need to jump
        if(arr.size() == 1) return 0;
        // the number of elements in the array
        int n = arr.size();
        // a vector to mark the visited indices
        vector<bool> vis(n, 0);

        // a map to store the indices of the same value in the array
        // we use a queue to store the indices of the same value in the array so we can pop the indices and not loop over them again when we have an element with the same value
        map<int,queue<int>> ma;

        // we store the indices of the same value in the array in the map
        for(int i = 0; i < n; i++)
            ma[arr[i]].push(i);

        // we use a queue to store the indices of the elements we can jump to
        queue<int> q;
        // we push the first index to the queue
        q.push(0);
        // we mark the first index as visited
        vis[0] = 1;
        // the number of jumps
        int cnt = 0;
        
        // BFS
        while(q.size()){
            // the number of elements in the current level
            int k = q.size();
            // we increase the number of jumps
            cnt++;
            while(k--){
                // we get the current index
                int x = q.front();
                q.pop();

                // we check if the index - 1 is valid and not visited before and we push it to the queue
                if(x != 0){
                    if(!vis[x - 1]){
                        vis[x - 1] = 1;
                        q.push(x - 1);
                    }
                }

                // we check if the index + 1 is valid and not visited before and we push it to the queue
                if(!vis[x + 1]){
                    // we check if the index + 1 is the last index and we return the number of jumps if it is
                    if(x + 1 == n - 1) return cnt;
                    vis[x + 1] = 1;
                    q.push(x + 1);
                }

                // we check if the index is in the map and we push all the indices of the same value to the queue
                while(ma[arr[x]].size()){
                    // we get the index of the same value
                    auto y = ma[arr[x]].front();
                    // we pop the index of the same value
                    ma[arr[x]].pop();
                    // we check if the index is not visited before and we push it to the queue
                    if(!vis[y]){
                        // we check if the index is the last index and we return the number of jumps if it is
                        if(y == n - 1) return cnt;
                        vis[y] = 1;
                        q.push(y);
                    }
                }
            }
        }
        // we will never reach this line but we return -1 to avoid warnings and errors from leetcode
        return -1;
    }
};
