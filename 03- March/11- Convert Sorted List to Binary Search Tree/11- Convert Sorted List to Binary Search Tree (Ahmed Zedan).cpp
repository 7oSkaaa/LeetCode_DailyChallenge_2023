// author : ahmed zedan 
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
    vector<int>v ; // values in linked list
    // divide and conquer
    TreeNode* Tree(int l , int r){
        if(l>r) return nullptr ; 
        int mid = l+(r-l)/2 ; // middle node in subtree
        // create new TreeNode and get value and left child and right child 
        TreeNode* root = new TreeNode(v[mid],Tree(l,mid-1),Tree(mid+1,r)) ; 
        return root ; 
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // add linked list values to vector
        while(head){
            v.push_back(head->val) ; 
            head = head->next  ; 
        }
        int n = v.size() ; // number of nodes 
        return Tree(0,n-1) ; 
    }
};