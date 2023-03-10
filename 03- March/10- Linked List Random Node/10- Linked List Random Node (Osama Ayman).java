// Author: Osama Ayman
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 // Reservoir sampling: R-Algo
 // space O(1), time O(n) for each getRandom()
 class Solution {
    ListNode head;
    public Solution(ListNode head) {
        this.head=head;
    }
    Random rand = new Random();
    public int getRandom() {
        // Reservoir of size 1 (index=0) if random number generated up to counter (number of elements seen so far) is equal to 0, replace it to be the new result.
        int counter=0, res=head.val;
        ListNode node = head;
        while(node!=null){
            counter++;
            if(rand.nextInt(counter) == 0) res=node.val;
            node=node.next;
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */