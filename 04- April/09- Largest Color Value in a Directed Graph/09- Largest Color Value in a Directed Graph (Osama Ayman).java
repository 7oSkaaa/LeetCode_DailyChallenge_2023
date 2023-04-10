// Author: Osama Ayman
// Time: O(n+e)
// Space: O(n)
class Solution {
    int globalRes = 0;
    Map<Integer, int[]> hm = new HashMap<>();
    public int largestPathValue(String colors, int[][] edges) {
        
        // get all paths, keep track of freq of colors in each path
        int nodes = colors.length();
        // building our adjacency list, so we can traverse the graph
        List<Integer>[] adjList = new ArrayList[nodes];
        for(int i=0; i<nodes; i++){
            adjList[i] = new ArrayList<>();
        }
        for(int[] e: edges){
            adjList[e[0]].add(e[1]);
        }
       
        // must loop over each node because the graph can be disconnected.
        for(int i=0; i<nodes; i++){
            // if dfs returns -1, then there is a cycle
            if(dfs(i, adjList, new HashSet<>(), colors) == -1) return -1;
        }

        return globalRes;

    }
 
    private int dfs(int node, List<Integer>[] adjList, Set<Integer> vis, String colors){

        if(vis.contains(node)) return -1;
        vis.add(node);

        // cur freq array for this node
        int[] tmp = new int[26];

        for(int child: adjList[node]){
            // if child is not visited yet, visit it first
            if(!hm.containsKey(child)){
                if(dfs(child, adjList, vis, colors) == -1) return -1;
            }
            
            int[] childFreq = hm.get(child);
            // updating tmp with the max value color for each child
            for(int i=0; i<26; i++){
                tmp[i] =  Math.max(tmp[i], childFreq[i]);
            }
        }
        // adding the cur color
        tmp[colors.charAt(node)-'a']++;
        // updating the max
        for(int x: tmp){
            globalRes = Math.max(globalRes, x);
        }
        // saving the current frequency array of color for this node
        hm.put(node, tmp);
        // remove cur node from visited set, as we are leaving it now
        vis.remove(node);
        // indicates that there is no cycle
        return 0;
    }
}