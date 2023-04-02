// Author: Mina Magdy

/*
1- the last position of postorder traversal always gives you the root of the current tree
2- let's search for this root in inorder traversal
   which allow you to know that its right elements is the right subtree and its left elements is the left subtree
3- then let's go for each subtree and do the same thing from step 1

recommendation: go to right subtree first because postorder gives you the right nodes in last positions and we are moving from last position
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = size(inorder), postIdx = n-1;
        return build(inorder, postorder, 0, n-1, postIdx);
    }
    TreeNode* build(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& postIdx) {
        if(inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = find(begin(in), end(in), root -> val) - begin(in);
        root -> right = build(in, post, inIdx+1, inEnd, postIdx);
        root -> left  = build(in, post, inStart, inIdx-1, postIdx);
        return root;
    }
};

/*
Example:
(3)
inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]

lastPost = 3 -> last index in postorder is the root 
searchIn = 1 -> at index 1 in inorder so [9] is the left subtree and [15, 20, 7] is the right subtree

======> GO RIGHT SUBTREE of (3)
(20)
inorder = [15,20,7], postorder = [9,15,7,20]

lastPost = 20 -> last index in postorder is the root
searchIn = 1 -> at index 1 in inorder so [15] is the left subtree and [7] is the right subtree

======> GO RIGHT SUBTREE of (20)
(7)
inorder = [7], postorder = [9,15,7]

lastPost = 7 -> last index in postorder is the root
searchIn = 0 -> at index 0 in inorder so [] is the left subtree and [] is the right subtree
NOTE: no left subtree and no right subtree so, this is a leaf node 

======> GO LEFT SUBTREE of (20)
(15)
inorder = [15], postorder = [9,15]
             
lastPost = 15 -> last index in postorder is the root
searchIn = 0 -> at index 0 in inorder so [] is the left subtree and [] is the right subtree
NOTE: no left subtree and no right subtree so, this is a leaf node 

======> GO LEFT SUBTREE of (3)
(9)
inorder = [9], postorder = [9]
             
lastPost = 9 -> last index in postorder is the root
searchIn = 0 -> at index 0 in inorder so [] is the left subtree and [] is the right subtree
NOTE: no left subtree and no right subtree so, this is a leaf node 

*/
