// Author: Ahmed Gamal

/**
 * @param {number[][]} roads
 * @param {number} seats
 * @return {number}
 */

// for this problem we want to find the minimum cost to travel from all cities to the capital
// each city has a number of seats and each seat can carry one person only
// if we have a city with 5 seats and 10 people we need to travel with 2 cars
// lets solve this problem for each city recursively and sum the cost of traveling from each city to the capital
// the cost of traveling from city u to city v is ceil(subTreeSize(v) / seats) (assuming that the whole subTreeSize(v) is traveling from u to v after they reach v)


var minimumFuelCost = function(roads, seats) {
    // adj: adjacency list
    let adj = Array(roads.length + 1).fill(0).map(x => []);

    // build the graph
    roads.forEach(([u, v]) =>  {
        adj[u].push(v);
        adj[v].push(u);
    });

    // ans: the answer (the minimum cost to travel from all cities to the capital)
    let ans = 0;

    // dfs: recursive function to find the subTreeSize of each city
    let dfs = (src, par) => {
        // cnt: the subTreeSize of the current city (initially 1 because the city itself)
        let cnt = 1;

        // for each child of the current city
        adj[src].forEach(nxt => {
            // if the child is not the parent of the current city
            if(nxt !== par){
                // find the subTreeSize of the child
                let subTreeCnt = dfs(nxt, src);

                // add ceil(subTreeSize / seats) to the answer
                ans += Math.ceil(subTreeCnt / seats);

                // add the subTreeSize of the child to the subTreeSize of the current city
                cnt += subTreeCnt;
            }
        });

        // return the subTreeSize of the current city
        return cnt;
    }

    // call dfs from the capital (city 0)
    dfs(0, -1);

    return ans;
};