// Author: Ahmed Hossam

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If the linked list is empty or has only one node
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;

        // Store the next node in a variable
        ListNode* next = head -> next;

        // Recursively swap the pairs of nodes
        head -> next = swapPairs(next -> next);
        next -> next = head;

        // Return the new head of the swapped linked list
        return next;
    }
};
