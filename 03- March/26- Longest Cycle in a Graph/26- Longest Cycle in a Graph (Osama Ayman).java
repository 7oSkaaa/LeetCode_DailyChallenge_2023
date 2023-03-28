// Author: Osama Ayman
class Solution {
    // global variable to save the result 
    int res=-1;
    // Set to save the visited nodes (So, we don't visit them again)
    Set<Integer> vis = new HashSet<>();

    public int longestCycle(int[] edges) {
        // check each node
        for(int i=0; i<edges.length; i++){
            // if not visited, run dfs
            if(!vis.contains(i)){
                dfs(i, new HashMap<>(), edges, 0);
            }
            
        }
        return res;
    }
    private void dfs(int cur, Map<Integer, Integer> curPath, int[] edges, int count){
        // if cur node has no edge, return
        if(cur==-1) return;
        // if this node was seen before, then there is a cycle.
        // the size of the cycle is the count - the cached count of the cur node
        // all other nodes in the cycle has the same cycle size, so no need to check 
        // them.
        if(curPath.containsKey(cur)){
            res=Math.max(res, count - curPath.get(cur));
            return;
        }
        if(vis.contains(cur)) return;
        // add this node as visited
        vis.add(cur);
        // put the cur node in  the hash map with its corresponding count
        curPath.put(cur, count);
        // go to the next edge and increment count
        dfs(edges[cur], curPath, edges, count+1);

    }
}