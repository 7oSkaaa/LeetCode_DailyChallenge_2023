// Author: Osama Ayman
// Time: O(n*n*m)
// Space: O(n*n)
class Solution {
    public int numSimilarGroups(String[] strs) {
        // adjacency map to represent the graph
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int n = strs.length;
        // adding edges if they are similar
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i], strs[j])){
                    // adding undirected edge (bi-directional)
                    adj.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                    adj.computeIfAbsent(j, k -> new ArrayList<>()).add(i);
                }
            }
        }
        int connectedComponents = 0;
        Set<Integer> vis = new HashSet<>();
        for(int i=0; i<n; i++){
            if(!vis.contains(i)){
                connectedComponents++;
                dfs(i, adj, vis);
            }
        }
        return connectedComponents;
    }
    private void dfs(int node, Map<Integer, List<Integer>> adj, Set<Integer> vis){
        if(vis.contains(node) || !adj.containsKey(node)) return;
        vis.add(node);
        for(int neigh: adj.get(node)){
            dfs(neigh, adj, vis);
        }
    }
    private boolean isSimilar(String s1, String s2){
        char c1='.',c2='.';
        
        for(int i=0; i<s1.length(); i++){
            // if they are equal, continue
            if(s1.charAt(i) == s2.charAt(i)) continue;
            // if they are not equal and c1 is not set, set c1 and c2
            if(c1=='.'){
                c1=s1.charAt(i);
                c2=s2.charAt(i);
            }
           // if they are equal and c1 and c2 are set, but they are not equal to the
           //char of the other string, return false
            else if(!(s1.charAt(i) == c2 && s2.charAt(i) == c1) ){
                return false;
            }

            
        }
        return true;
    }
}