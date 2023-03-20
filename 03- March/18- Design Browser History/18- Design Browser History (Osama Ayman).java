// Author: Osama Ayman
// Use a Doubly linked List so you can easily go backward and forward
class Node{
    Node next, prev;
    String val;
    public Node(String val){
        this.val=val;
        next=null;
        prev=null;
    }
}
class BrowserHistory {
    Node cur;
    // initilaizes current node
    public BrowserHistory(String homepage) {
        cur = new Node(homepage);
    }
    // add new node and set it to cur
    public void visit(String url) {
        Node neww = new Node(url);
        cur.next=neww;
        neww.prev=cur;
        cur=neww;
    }
    // go back the number of steps required but do not go out of boundaries
    public String back(int steps) {
        while(cur.prev!=null && steps-->0){
            cur=cur.prev;
        }
        return cur.val;
    }
    // go forward the number of steps required but do not go out of boundaries
    public String forward(int steps) {
        while(cur.next!=null && steps-->0){
            cur=cur.next;
        }
        return cur.val;
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */