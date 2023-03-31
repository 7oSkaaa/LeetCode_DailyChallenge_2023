// Author: Osama Ayman
class Solution {
    public int minReorder(int n, int[][] connections) {
        // run BFS from node 0, if the child node does not point to parent node, increment the result

        // bidirectional adjList to visit all nodes
        Set<Integer>[] adjList = new HashSet[n];
        // original edges only
        Set<Integer>[] original = new HashSet[n];
        // Initializing
        for(int i=0; i<n; i++) {
            adjList[i]=new HashSet<>(); 
            original[i]=new HashSet<>();
        }
        // Adding edges
        for(int[] c: connections){
            adjList[c[0]].add(c[1]); original[c[0]].add(c[1]);
            adjList[c[1]].add(c[0]);
        }
        Queue<Integer> q = new LinkedList<>();
        Set<Integer> vis = new HashSet<>();
        q.add(0);
        int res=0;
        // BFS
        while(!q.isEmpty()){
            // get number of nodes in current level
            int size=q.size();
            for(int i=0; i<size; i++){
                int cur = q.poll();
                // mark it as visited
                vis.add(cur);
                for(int child: adjList[cur]){
                    // if already visited, continue
                    if(vis.contains(child)) continue;
                    q.add(child);
                    // if the child does not point to parent, increment the result
                    if(!original[child].contains(cur)) res++;
                }
            }
            
        }
        return res;
    }
}