// author : Omar Sanad
class Solution {
public:
    // a function to check if two BST are the equal
    bool areSame(TreeNode* r1, TreeNode* r2) {
        if (r1 == NULL && r2 == NULL)   return true;
        if ((bool(r1) ^ bool(r2)))  return false;   // if one is NULL and the other is not NULL
        if (r1->val != r2->val) return false;
        return areSame(r1->left, r2->left) && areSame(r1->right, r2->right);
    }

    // a function to insert a node in a BST
    TreeNode* insert(int val, TreeNode* root) {
        if (!root)
            return new TreeNode(val);
        
        if (root->val > val)
            root->left = insert(val, root->left);
        else
            root->right = insert(val, root->right);
        
        return root;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector <TreeNode*> ans;

        // we generate all the permutations from 1 to n
        vector < int > perm(n);

        iota(perm.begin(), perm.end(), 1);
        
        do{
            // initialize the root of the curr permutation
            TreeNode* root = new TreeNode(perm.front());
            
            // insert each value of the permutation in the BST
            for (int i = 1; i < n; i++)
                insert(perm[i], root);
            
            // check if we have already added a BST that is equal to the curr BST
            for (int i = 0; i < ans.size(); i++)
                if (areSame(root, ans[i]))
                    goto here;

            ans.emplace_back(root);

            here:
                continue;
        }while(next_permutation(perm.begin(), perm.end()));


        // return the answer to the problem
        return ans;
    }
};
