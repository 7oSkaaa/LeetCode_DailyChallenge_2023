//Author: Abdelrrahman Elhaddad

/*
 Intuition:
  If we want to find the minimum edge which I can pass on through my way to the n node,
  Then we have to find the minimun edge in the same connected component that contains 1 and n node
*/

let mn = Infinity;
let graph: number[][][]; // Declaring graph vector to store all of our edges
let visited: boolean[]; // To mark visited nodes

function DFS(i: number): void {
    if (visited[i]) // If I entered a visited node then stop traversing that way and return 
        return;

    visited[i] = true; // Marking current node as visited

    for (let j = 0; j < graph[i].length; j++) {
        const child = graph[i][j];
                                        
        mn = Math.min(mn, child[1]); / Getting the minimum edge
        DFS(child[0]); // Move to the next node
    }
}

function minScore(n: number, roads: number[][]): number {
    mn = Infinity;
    graph = new Array(n + 1); // Setting size
    for (let i = 1; i <= n; i++) // Setting Initial value to each index as an empty array
        graph[i] = [];

    visited = new Array(n + 1); // Setting size
    for (let i = 1; i <= n; i++) // Setting Initial value to each index as false
        visited[i] = false;

    roads.forEach((road) => {
      // Storing our edges both ways because our graph is bidirectional
        graph[road[0]].push([road[1], road[2]]);
        graph[road[1]].push([road[0], road[2]]);
    });

    DFS(1); // Starting to traverse through the graph from node 1

    return mn;
};
