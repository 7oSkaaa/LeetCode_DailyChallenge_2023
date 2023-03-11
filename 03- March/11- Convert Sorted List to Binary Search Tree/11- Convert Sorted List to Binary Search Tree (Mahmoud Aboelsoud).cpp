// Author: Mahmoud Aboelsoud


class Solution {
public:
    // we will use a vector to store the values of the linked list
    // then we will use the vector to build the binary search tree
    // the vector is sorted so we use a reverse inorder traversal to build the tree
    // the middle element of the vector will be the root of the tree
    // the left half of the vector will be the left subtree of the root
    // the right half of the vector will be the right subtree of the root
    // we will use a recursive function to build the tree
    // the function will take the left and right indices of the vector
    // the function will return the root of the subtree
    // the function will be called with the indices of the whole vector
    // the function will return the root of the tree

    // vector to store the values of the linked list
    vector<int> v;

    // recursive function to build the tree
    TreeNode* build(int l, int r){
        // base case if the left index is greater than the right index return NULL
        if(l > r) return NULL;
        
        // find the middle index
        int mid = l + (r - l) / 2;
        
        // create the root of the subtree and call the function recursively to build the left and right subtrees 
        TreeNode* root = new TreeNode(v[mid]);
        root -> left = build(l, mid - 1);
        root -> right = build(mid + 1, r);

        // return the root of the subtree
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // store the values of the linked list in the vector
        while(head != NULL){
            v.push_back(head -> val);
            head = head -> next;
        }

        // call the recursive function to build the tree and return the root of the tree
        return build(0, int(v.size()) - 1);
    }
};
