// author: Esraa Syam
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // we can use divide and conquer to solve this problem
        // time complexity: O(nlogn)
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        ListNode *slow = head, *fast = head, *pre = NULL;
        while (fast and fast->next) {
            pre = slow; // pre is the node before slow
            slow = slow->next; // slow is the middle node
            fast = fast->next->next; // fast is the last node
        } 
        // use pre to cut the list into two parts
        // the left part is the left subtree
        // the right part is the right subtree
        pre->next = NULL;
        TreeNode *root = new TreeNode(slow->val); // the middle node is the root
        root->left = sortedListToBST(head); // the left part is the left subtree
        root->right = sortedListToBST(slow->next); // the right part is the right subtree
        return root; 
    }
};