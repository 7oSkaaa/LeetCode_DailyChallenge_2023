// Author: Lama Salah

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    // TWO POINTERS SOLUTION 

public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Initialize two pointers p1 and p2 to the head of the linked list.
        ListNode *p1 = head, *p2 = head, *beginning;

        // Move the pointer p2 k-1 nodes (This puts p2 at the kth node from the beginning of the list).
        for (int i = 0; i < k-1; i++)  
            p2 = p2 -> next;

        // Initialize a pointer beginning to the node pointed to by p2.
        beginning = p2;

        // Move both pointers p1 and p2 simultaneously until p2 reaches the end of the linked list. 
        // At this point, p1 will be pointing to the kth node from the end of the list.
        while (p2 -> next){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        // Swap values of kth node from beginning and kth node from end.
        swap(beginning -> val, p1 -> val);
        
        // Return the head of the linked list.
        return head;
    }
};