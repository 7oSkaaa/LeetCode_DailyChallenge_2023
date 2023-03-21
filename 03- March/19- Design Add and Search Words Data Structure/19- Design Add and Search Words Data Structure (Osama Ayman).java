// Author: Osama Ayman

// Trie Node
class Node{
    HashMap<Character, Node> children;
    boolean end;
    public Node(){
        children=new HashMap<>();
        end=false;
    }
}
class WordDictionary {
    // root of the Trie
    Node root;
    public WordDictionary() {
        root = new Node();
    }
    
    public void addWord(String word) {
        Node cur = root;
        // traverse all chars in word
        for(char c: word.toCharArray()){
            // if cur char is found in the children of cur node, move to it.
            if(cur.children.containsKey(c)){
                cur = cur.children.get(c);
            }
            // if not found, create a child and move to it.
            else{
                Node neww = new Node();
                cur.children.put(c, neww);
                cur=neww;
            }
        }
        // mark last node as a complete word
        cur.end=true;
    }
    
    public boolean search(String word) {
        // easier to solve it recursively
        return find(word.toCharArray(),0, root);
    }

    private boolean find(char[] word, int idx, Node cur){
        // base case
        if(idx==word.length) return cur.end;
        // try all children
        if(word[idx]=='.'){
            for(char child: cur.children.keySet()){
                if(find(word, idx+1, cur.children.get(child))) return true;
            }
            return false;
        }
        // if cur char not found in children return false
        if(!cur.children.containsKey(word[idx])) return false;
        // complete to check the rest of the word
        return find(word, idx+1, cur.children.get(word[idx]));
        
    }
   
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */