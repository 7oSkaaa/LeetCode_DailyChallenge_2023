// Author: Osama Ayman
/*  save all reachable nodes from node1 with their distances to node1.
    save all reachable nodes from node2 with their distances to node2.
    return the smallest-indexed node that the maximum distance from it to nodes 1,2 is minimized.
 */
class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        //key is node number, val is distance
        HashMap<Integer, Integer> l1 = new HashMap<>();
        HashMap<Integer, Integer> l2 = new HashMap<>();
        getReachable(l1, new HashSet<>(), node1, edges, 0); 
        getReachable(l2, new HashSet<>(), node2, edges, 0);
        int minDist = Integer.MAX_VALUE;
        int res = Integer.MAX_VALUE;
        for(int node: l1.keySet()){
            if(l2.containsKey(node)){
                int tmp = Math.max(l1.get(node), l2.get(node));
                if(tmp < minDist){
                    minDist = tmp;
                    res = node;
                }
                else if (tmp==minDist){
                    res = Math.min(res, node);
                }
            }
        }
        return res == Integer.MAX_VALUE ? -1:res;
    }
    private void getReachable(HashMap<Integer, Integer> hm, HashSet<Integer> vis, int curNode, int[] edges, int dist){
        if(vis.contains(curNode)) return;
        vis.add(curNode);
        hm.put(curNode, dist);
        if(edges[curNode]==-1) return;
        getReachable(hm, vis, edges[curNode], edges, ++dist );
    }
}