// Author: Osama Ayman
class Solution {
    public int minScore(int n, int[][] roads) {
        // visited set to hold all reachable nodes
        Set<Integer> vis = new HashSet<>();
        // adjacency list to represent our graph
        List<Integer>[] adjList = new ArrayList[n+1];
        for(int i=0; i<=n; i++){
            adjList[i]=new ArrayList<>();
        }
        // adding the bidirectional edges
        for(int[] r: roads){
            adjList[r[0]].add(r[1]);
            adjList[r[1]].add(r[0]);
        }

        dfs(vis, 1, n, adjList);
        vis.add(n);
        int res=Integer.MAX_VALUE;
        // check if the node is reachable then we can take its distance
       for(int[] r: roads){
           if(vis.contains(r[0])) res=Math.min(res, r[2]);
        }
        return res;
    }
    // mark all nodes that can be reached
    void dfs(Set<Integer> vis, int cur, int n, List<Integer>[] adjList){
        if(vis.contains(cur)) return;
        if(cur==n) return;
        vis.add(cur);
        for(int neigh: adjList[cur]){
            dfs(vis, neigh, n, adjList);
        }
    }
}