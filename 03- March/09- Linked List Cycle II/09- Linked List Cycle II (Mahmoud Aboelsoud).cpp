// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to loop through the list and check if the current node is in the set (visited before) or not
    // if it is, then we have a cycle and we return the current node
    // if not, we add the current node to the set and move to the next node
    // if we reach the end of the list, then we return NULL (no cycle)


    ListNode *detectCycle(ListNode *head) {
        // set to store the visited nodes
        unordered_set<ListNode*> st;

        // loop through the list
        while(head != NULL){
            // if the current node is in the set, then we have a cycle starting from this node
            if(st.count(head)) return head;
            // if not, we add the current node to the set and move to the next node
            st.insert(head);
            head = head -> next;
        }
        // if we reach the end of the list, then we return NULL (no cycle)
        return NULL;
    }
};
