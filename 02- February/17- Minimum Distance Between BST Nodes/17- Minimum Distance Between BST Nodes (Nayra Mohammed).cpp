// Author : Nayra Mohammed

// Solution 1:

#define sz(s) (int(s.size()))
class Solution
{
public:
    /*
        - All we gonna do is traversing through our BST and store the values of it's nodes
        - Sort these values and find the minimum difference between every consecutive two elements "kinda greedy"
    */

    vector<int> v; // store the values of BST's nodes

    void Store_Items(TreeNode *st)
    {
        if (!st) // if current node is empty we stop traversing through it
            return;

        v.push_back(st->val); // store current node value

        Store_Items(st->left);  // traverse through the left child of current node
        Store_Items(st->right); // traverse through the right child of current node
    }

    int minDiffInBST(TreeNode *root)
    {

        Store_Items(root); // start traversing through BST

        sort(v.begin(), v.end()); // sort the values of BST's nodes

        int mn = 1e9; // -> store minimum difference between any two node

        for (int i = 1; i < sz(v); i++) // for every consecutive two values update mn with their difference
            mn = min(mn, v[i] - v[i - 1]);

        return mn;
    }
};


// Solution 2 (Knowin' BST features):

class Solution
{
public:
  
    /*
        - As we are in a BST , then the tree itself is sorted..
          for each node, the left-child node's a smaller value than it;Unlike the right-child node as it's a bigger value than it.

        - So we can traverse through BST using In-Order traverse to calculate the answer while traversing

        * In case not knowing BST :) References: - https://www.programiz.com/dsa/binary-search-tree
                                                 - https://www.geeksforgeeks.org/binary-search-tree-traversal-inorder-preorder-post-order/
    */


    int Min_Diff(TreeNode *curr, int &pre)// here we need to use pre by its reference to be used in previous calls in case of traversing through left child :)
    {
        if (!curr) // in case of an emtpy node we return with a big value and stop traversing through it
            return 1e9;

  
        int ans = Min_Diff(curr->left, pre);// start traversing through left child "lower value"
        
        // if we have a pre node then we calculate the difference between them
        int mn_diff = (pre == -1 ? 1e9 : abs(pre - curr->val));
        
        // update pre value for upcoming traversing
        pre = curr->val;

        //traverse through right-child "higher value"
        // store the minimum value between all of them
        ans = min({ans, mn_diff, Min_Diff(curr->right, pre)});
  
        return ans;// return answer for current state
    }
  
    int minDiffInBST(TreeNode *root)
    {
        int pre = -1;// root's previous node's value = -1
  
        return Min_Diff(root, pre); //calculate the answer
    }
};
