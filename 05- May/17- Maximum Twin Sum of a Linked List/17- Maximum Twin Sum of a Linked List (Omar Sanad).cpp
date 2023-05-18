// author : Omar Sanad

class Solution {
public:
    int pairSum(ListNode* head) {
        // declare a stack to store the nodes in a reversed order
        stack < ListNode* > st;

        // declare a variable cur as a pointer to iterate over the list
        ListNode *cur = head;

        // iterate over the list and push the nodes in the stack
        while (cur){ 
            st.push(cur);
            cur = cur->next;
        }

        // declare a variable to store the answer and initialize it to 0
        int maxSUM = 0;

        // declare a variable node as a pointer to iterate over the list
        ListNode *node = head;

        // iterate over the list from the front using the variable node,
        // and from the back using the stack
        // and maximizing the answer 
        while (st.size()) {
            maxSUM = max(maxSUM, node->val + st.top()->val);
            st.pop();
            node = node->next;
        }

        // return the answer
        return maxSUM;
    }
};

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
