// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // check if p and q are null
        if(p==NULL && q==NULL){
            return true;
        }
        // check if p equal null and q not
        if(p==NULL){
            return false;
        }
        // check if q equal null and p not
        if(q==NULL){
            return false;
        }
        // check if p not equal q
        if(p->val!=q->val){
            return false;
        }
        // if p equal to q then check for left subtree and right subtree
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};