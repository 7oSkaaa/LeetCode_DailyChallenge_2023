// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

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
    // vector to store the nodes 
    vector<ListNode*>nodes;
    TreeNode* sortedListToBST(ListNode* head) {
        while(head){
            // push current node and go to the next 
            nodes.push_back(head);
            head=head->next;
        }
        // get the BST(Binary Search Tree)
        return getTree(0,nodes.size()-1);
    }
    TreeNode* getTree(int l,int r){
        // check if left pointer greater than right pointer 
        // then stop
        if(l>r){
            return NULL;
        }
        // check if left pointer equal right pointer
        // return current node
        if(l==r){
            return new TreeNode(nodes[l]->val);
        }
        // get the mid node
        int mid=(l+r)/2;
        // return tree node 
        // the middle node will be the root node
        // and subarray from left to middle will be left sub tree
        // and subarray from right to middle will be right sub tree
        return new TreeNode(nodes[mid]->val,getTree(l,mid-1),getTree(mid+1,r));
    }
};
