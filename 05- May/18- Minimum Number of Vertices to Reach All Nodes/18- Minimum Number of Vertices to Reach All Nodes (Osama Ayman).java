// Author: Osama Ayman
// Time: O(N + E)
// Space: O(N)
class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        boolean[] incomingEdge = new boolean[n];
        for(List<Integer> e: edges){
            incomingEdge[e.get(1)] = true;
        }
        List<Integer> res = new ArrayList<>();
        // Any node that has no incoming edge can not be visited untill we start from it
        for(int i=0; i<n; i++){
            if(!incomingEdge[i]){
                // add node to the result list
                res.add(i);
            }
        }
        return res;
    }
}