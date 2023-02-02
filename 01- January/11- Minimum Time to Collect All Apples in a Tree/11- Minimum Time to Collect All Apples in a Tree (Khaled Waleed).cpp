// Author           : Khaled Waleed
// File Created on  : 11/Jan/2023 on 02:18:16


// Solution beats 100% in time and beats 100% in memory !

// mustVisit nodes are ones that either have apples or must be visited to get to a node which has apples

// The Idea is you will notice that the answer is the number of all nodes you have to visit multiplied by 2 (except for zero)!!
// because to get to any point you have to go there and then come back, 2 moves per any visited node except for zero !
// because you already start at zero, you don't go there then come back !

// so our goal is to determine the nodes we NEED to visit
// we check every node which has apples in it then go mark all the nodes in the path needed to
// go to node-zer starting at that node
// the answer is all the mustVisited nodes * 2 (excluding node-zero as mentioned)


class Solution {
public:

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        // we choose the least-in-number neighbour because to follow the path from some point to zero
        // you always have to go to the least neighbour in number
        // intilaize to max becasue we need to minimize that number with new edges added
        vector<int> leastNeighbour(n, INT32_MAX);

        // for each edge, we conclude the least-in-number neighbour for the two nodes in edge
        for (auto & i : edges) {
            // down to up
            leastNeighbour[i[0]] = min(i[1], leastNeighbour[i[0]]);
            leastNeighbour[i[1]] = min(i[0], leastNeighbour[i[1]]);

        }

        // here we store the nodes we NEED to visit
        // initialized to false so later on when we follow the path to node-zero we terminate if
        // we find a start of a previously visited path thus... saving time for not tracing the same path twice
        // basically... if node 3 is connected to node 2 and we know that we visited node 2 then we don't need to trace
        // to node-zero , only trace the path until node 2 (all nodes from 2 to 0 were already checked before)
        vector<bool>mustVisit(n ,false);

        // we go from last to start because checking the longer paths makes it faster for us to mark other nodes
        int j = 0;
        for (int i = n - 1; i > 0; --i) {
            if(hasApple[i]){
                j = i;
                // if it has apple then mark its path by marking the point then going to the least neighbour
                // repeat until reach zero-node or a node we previously visited
                while(not mustVisit[j] && j != 0){
                    mustVisit[j] = true;
                    j = leastNeighbour[j];
                }
            }
        }

        int cntr = 0;
        for (auto i : mustVisit) {
            cntr += int(i);
        }

        return  cntr*2;
    }
};