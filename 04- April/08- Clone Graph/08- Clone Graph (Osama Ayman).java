/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/
// Author: Osama Ayman
/*
 * Create a copy given the original node. 
 * Then, loop over the original node.neighbors, call the function recursively again to create node for the child. 
 * Once you return, assign the created new child to the neighbors of the copy of the original node.
 */
// Time: O(n+E)
// Space: O(n)
class Solution {
    // map to save references to the newly created nodes
    Map<Integer, Node> map = new HashMap<>();
    public Node cloneGraph(Node node) {
        if(node == null) return null;
        if(map.containsKey(node.val)) return map.get(node.val);
        Node neww = new Node(node.val);
        map.put(node.val, neww);
        for(Node child: node.neighbors){
            Node newChild = cloneGraph(child);
            neww.neighbors.add(newChild);
        }
        return map.get(node.val);
    }
}