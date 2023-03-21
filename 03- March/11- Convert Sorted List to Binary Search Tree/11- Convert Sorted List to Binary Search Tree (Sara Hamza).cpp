//Author: Sara Hamza
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
    TreeNode* solve(int l, int r, vector<int>&values){
        // invalid case
        if(l > r)
            return nullptr;

        // leaf node
        if(l == r)
            return new TreeNode(values[l]);

        // build
        int mid = l + (r - l) / 2, n = values.size();

        TreeNode* node = new TreeNode(values[mid]);

        node->left = solve(l, mid-1, values);
        node->right = solve(mid+1,r, values);

        return node;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        /*
            1. get the values of the listNode in a vector "values".
            2. we need to convert the whole vector (from left = 0 to right = its size - 1) into a tree.
            3. so, get the mid of this vector and convert it into a TreeNode
            4. calculate the left and right of this node recursevly
                by repeating these steps again on the left part of the vector (from l to mid-1)
                and the right part (from mid+1 to r)

                note that the mid is already converted into treeNode so, exclude it from both parts

                while repeating these steps avoid the invalid vector part when  l is > r.

                also the base case of this recursive function is to return the leaf node.
                this will occur when l == r meaning that there is only one value in the vector.
        */
        vector<int>values;
        while(head) {
            values.push_back(head->val);
            head = head->next;
        }

        return solve(0, values.size()-1, values);
    }
};
