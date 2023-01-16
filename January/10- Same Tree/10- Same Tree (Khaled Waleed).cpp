// Author           : Khaled Waleed
// File Created on  : 10/Jan/2023 on 04:02:45

// This is a Solution for Problem LC100_Same_Tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // basically, it's a recursive algorithm
        // on every node you check if the value of that node is equal to the value of the corresponding node in other tree
        // if they are equal then check if the left is equal to the left and right equal to right

        if(p && q){ // if both of them are not null popinters
            if(p->val == q->val){ // if both of them has the same value
                return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); // return if left qual left and right equal right
            }else{
                return false; // if the current nodes aren't equal to each other we terminate
            }
        }else{
            // if we reached this part then we know for a fact that either p or q or both are nullptr
            // then.. if they are both equal (both nullptr) then sure, they have the same "value" of being null
            // if the are different then they are not equal
            return (q==p);
        }
    }
};