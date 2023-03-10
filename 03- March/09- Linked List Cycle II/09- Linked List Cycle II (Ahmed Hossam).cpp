// Author: Ahmed Hossam

class Solution {
public:
    
    ListNode* find_cycle(ListNode* head, unordered_map < ListNode*, bool >& occ){
        // return the node if it is visited before
        if(!head || occ[head]) return head;
        
        // mark this node as visited node
        occ[head] = true;

        return find_cycle(head -> next, occ);
    }
    
    ListNode *detectCycle(ListNode *head) {
        // map to store the visited nodes
        unordered_map < ListNode*, bool > occ;

        // the node that make cycle
        return find_cycle(head, occ);
    }
};
