// Author: Ahmed Hossam

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Initialize pointers to the head of the list
        ListNode* one = head;
        ListNode* two = head;
        ListNode* curr = head;

        // Calculate the size of the list
        int sz = 0;
        while (curr)
            sz++, curr = curr -> next;

        // Move 'one' pointer to the kth node from the beginning
        for (int i = 1; i < k; i++)
            one = one -> next;

        // Move 'two' pointer to the kth node from the end
        for (int i = 1; i < sz - k + 1; i++)
            two = two -> next;

        // Swap the values of the two nodes
        swap(one -> val, two -> val);

        // Return the updated head of the list
        return head;
    }

};
