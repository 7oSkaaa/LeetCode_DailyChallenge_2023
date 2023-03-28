//Author: Abdelrrahman Elhaddad

/*
 Intuition:
    To know how many times that we will have to extract certain cables between two directly connected computers 
    and place them between any pair of disconnected computers, We will need to know two things:
    1- Is there enough cables to connect all the devices?
      We will know that by checking if we have cables more than or equal n - 1
      - If we have 4 computers we will need 3 cables. [o-o-o-o] -> 4 computers, 3 cables
    2- How many disconnected computers we need to connect?
      We will know that by using DFS to traverse through the graph
      and count how many connected components exist in our graph
 */

let graph: number[][] = []; // To store graph edges
let visited: boolean[] = []; // To mark visited nodes

function DFS(i: number): void {
    visited[i] = true; // Mark current node as visited
    graph[i].forEach((child) => {
        if (!visited[child]) // If the child node is not visited, Then we will enter it
            DFS(child);
    });
}

function makeConnected(n: number, connections: number[][]): number {
    visited.length = n;
    graph.length = n;

    if (connections.length < n - 1) // Checking if we have enough edges to connect all of the computers
        return -1; // If no return -1

    for (let i = 0; i < n; i++) { // Filling arrays with their initail value
        graph[i] = []
        visited[i] = false;
    }

    // Pushing every node's childs
    // Pushing both ways because our cables are bidirectional
    connections.forEach((conn) => {
        graph[conn[0]].push(conn[1]);
        graph[conn[1]].push(conn[0]);
    })

    let c = -1; // Initalizing our counter with -1

    for (let i = 0; i < n; i++) { // Iterating on all the nodes to check the unvisited
        if (!visited[i]) { // If not visited, Enter it and increment the counter by 1
            c++;
            DFS(i);
        }
    }

    return c; // Return the counter
};
