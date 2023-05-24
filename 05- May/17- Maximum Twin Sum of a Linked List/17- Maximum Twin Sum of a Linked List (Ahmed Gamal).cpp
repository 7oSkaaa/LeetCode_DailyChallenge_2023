// Author: Ahmed Gamal

// for this problem, we will use the two pointers technique
// we want to let one pointer point to the first node after the middle node
// and the other pointer point to the middle node
// then we will reverse the first half of the linked list
// then we will iterate over the two halves and get the maximum sum of the two nodes

// to achieve this, we need to have 4 pointers
// 1- cur: to iterate over the linked list (will point to the first node after the middle node)
// 2- fast: the fast pointer to iterate over the linked list and stop the iteration at the middle node
// 3- nxt: to save the next node of the current node
// 4- prv: to save the previous node of the current node

// nxt, prv: will be used to reverse the first half of the linked list

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *cur, *fast, *nxt, *prv = nullptr;
        cur = fast = head;

        while(fast) {
            fast = fast -> next -> next;
            nxt = cur -> next;
            cur -> next = prv;
            prv = cur;
            cur = nxt;
        }
        
        int ans = 0;
        while(cur) {
            ans = max(ans, prv -> val + cur -> val);
            cur = cur -> next;
            prv = prv -> next;
        }

        return ans;
    }
};