// Author: Osama Ayman
class Node{
    char val;
    List<Node> children;
    boolean end;
    public Node(char val){
        this.val=val;
        children = new ArrayList<>();
        end=false;
    }
}
class Trie {
    Node root;

    public Trie() {
        root = new Node('.');
    }
    
    public void insert(String word) {
        // using idx as an array because we want to pass it by reference!
        int[] idx = new int[1];
        // getting the longest prefix
        Node node = find(root, word, idx);
        // adding new nodes
        while(idx[0] < word.length()){
            Node neww = new Node(word.charAt(idx[0]));
            node.children.add(neww);
            node = neww;
            idx[0]++;
        }
        // mark it as a complete word
        node.end=true;
    }
    
    public boolean search(String word) {
        int[] idx = new int[1];
        Node node = find(root, word, idx);
        // 2 conditions must hold: 
        // all the word has been consumed & the last node is end
        return idx[0]==word.length() && node.end;
    }
    
    public boolean startsWith(String prefix) {
        int[] idx = new int[1];
        find(root, prefix, idx);
        return idx[0]==prefix.length();
    }
    // return the last node that matches the cur string
    private Node find(Node cur, String word, int[] idx){
        if(idx[0]==word.length()) return cur; 
        for(Node node: cur.children){
            if(node.val==word.charAt(idx[0])){
                idx[0]++;
                return find(node, word, idx);
            }
        }
        return cur;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */