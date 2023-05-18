// Author: Ahmed Gamal

// for this problem, we will use a recursive approach to solve it
// we will swap the first two nodes, then we will call the function again

// to achieve this, we need to some pointers
// 1- head (function parameter): to point to the current node
// 2- prv (function parameter): to point to the previous node of the current node (in the new linked list)
// 3- next: to point to the next node of the current node
// 4- next_next: to point to the next node of the next node of the current node

// we will use the prv pointer to move the connection between the previous node and the current node to the next node
// we will use the next_next pointer to move the connection between the current node and the next node to the next next node
// then we will move the connection between the next_next node and the next node to the current node

// we will call the function again with the next_next node as the current node and the current node as the previous node

class Solution {
    void solve(ListNode* head, ListNode* prv = nullptr) {
        if(not(head and head -> next)) {
            return;
        }

        if(prv) {
            prv -> next = head -> next;
        }
        auto next = head -> next;
        auto next_next = next -> next;

        head -> next = next_next;
        next -> next = head;

        solve(next_next, head);
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(not(head and head -> next))
            return head;
        
        auto ret = head -> next;
        solve(head);
        
        return ret;
    }
};