// Author: Osama Ayman
class Solution {
    public long countPairs(int n, int[][] edges) {
        // put each connected component in a set
        // {0,2,4,5} {1,6} {3}
        // 4*(7-4) + 2*(1) + 1*0 = 14
        Set<Integer> vis = new HashSet<>();
        List<Integer>[] adjList = new ArrayList[n];
        for(int i=0; i<n; i++) adjList[i]=new ArrayList<>();
        for(int[] e: edges){
            adjList[e[0]].add(e[1]);
            adjList[e[1]].add(e[0]);
        }
        // size of each set (connected component)
        List<Integer> sizes = new ArrayList<>();
        for(int i=0; i<n; i++){
            if(vis.contains(i)) continue;
            sizes.add(dfs(i, vis, adjList));
        }
        long count = n;
        long res=0;
        for(int s: sizes){
            count-=s;
            res+= s*count;
        }
        return res;

    }
    private int dfs(int cur, Set<Integer> vis, List<Integer>[] adjList){
        if(vis.contains(cur)) return 0;
        vis.add(cur);
        int res=1;
        for(int neigh: adjList[cur]){
            res+=dfs(neigh, vis, adjList);
        }
        return res;
    }
}