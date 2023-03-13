// Author: Ahmed Gamal

// for this problem, as the list is sorted, we can use divide and conquer to build the tree
// to build the tree to be balanced, we need to choose the middle element as the root of the tree and the left half of the list as the left subtree and the right half of the list as the right subtree
// because we have a linked list, we can't access the middle element in O(1) time, so we need to traverse the list to get the middle element
// we can do this recursively, by passing the left and right bounds of the list to the recursive function (divide and conquer)


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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // get the value of the node at the given index
    int get_node(ListNode* head, int idx){
        auto curr = head;
        while(idx--){
            curr = curr -> next;
        }
        return curr -> val;
    }

    // build the tree recursively
    TreeNode* solve(ListNode* head, int l, int r){
        // if the left bound is greater than the right bound, then we have reached the end of the half of the list
        if(l > r){
            return nullptr;
        }

        // get the middle element
        int m = l - (l - r) / 2;

        // build the tree recursively by choosing the middle element as the root and the left half of the list as the left subtree and the right half of the list as the right subtree
        return new TreeNode(get_node(head, m), solve(head, l, m - 1), solve(head, m + 1, r));
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // get the size of the list
        int size = 0;
        auto curr = head;
        while(curr){
            size++;
            curr = curr -> next;
        }

        // start building the tree from the original problem (the whole list)
        return solve(head, 0, size - 1);
    }
};