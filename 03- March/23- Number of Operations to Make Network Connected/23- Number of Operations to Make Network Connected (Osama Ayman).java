// Author: Osama Ayman
class Solution {
    public int makeConnected(int n, int[][] connections) {
        // min connections needed to connect all n computers is n-1
        // res is the number of computers that have no edges

        // can't connect all n computers with less than n-1 edges
        if(connections.length+1<n) return -1;
        Set<Integer> connected = new HashSet<>();
        List<Integer>[] adjList = new ArrayList[n];
        for(int i=0; i<n; i++) adjList[i]=new ArrayList<>();
        for(int[] c: connections){
            adjList[c[0]].add(c[1]);
            adjList[c[1]].add(c[0]);
        }
        // run dfs on each node. If the node is not visited add 1 then do the same 
        // with the other nodes.
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!connected.contains(i)){
                cnt++;
                dfs(adjList, i, connected);
            }
        }
        // the res is the count -1 because initially we added 1 as our set was empty
        return cnt-1;
    }
    private void dfs(List<Integer>[] adjList, int node, Set<Integer> connected){
        if(connected.contains(node)) return;
        connected.add(node);
        for(int neigh: adjList[node]){
            dfs(adjList, neigh, connected);
        }
    }
}