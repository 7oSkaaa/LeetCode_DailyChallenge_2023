// Author: Mina Magdy

const int MOD = 1e9 + 7;

class Solution {
public:
    // the BST structure
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    
    // Function to insert a value into a BST
    void insert(int val, TreeNode *root) {
        if (root->val < val) { // if the curr node has value less than "val" go right
            if (!root->right) { // if there are no more nodes, insert "val" in this place
                root->right = new TreeNode(val);
            }
            else {// else go deeper to the right
                insert(val, root->right);
            }
        }
        else {
            if (!root->left) { // if there are no more nodes, insert "val" in this place
                root->left = new TreeNode(val);
            }
            else { // else go deeper to the left
                insert(val, root->left);
            }
        }
    }
    
    // Function to calculate fast exponentiation (b^e mod MOD)
    int fast_pow(int b, int e) {
        int prod = 1;
        while (e) {
            if (e & 1) {
                prod = 1ll * prod * b % MOD;
            }
            e >>= 1;
            b = 1ll * b * b % MOD;
        }
        return prod;
    }
    
    vector<long long> fact;
    
    // Function to build a factorial lookup table
    void buildFact() {
        fact.resize(1005);
        fact[0] = 1;
        for (int i = 1; i < 1005; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
    }
    
    // Function to calculate nCr (combination)
    int nCr(int n, int r) {
        return fact[n] * fast_pow(fact[n - r], MOD - 2) % MOD * fast_pow(fact[r], MOD - 2) % MOD;
    }
    
    // Divide and Conquer function to count the number of valid ways
    // first: number of solution, second: number of elements
    pair<int, int> DAC(TreeNode *root) {
        if (!root) return {1, 0}; // if it's empty node then we have 1 solution, and 0 elements 
        if (!root->left && !root->right) return {1, 1}; // if it's leaf node then we have 1 solution, and 0 elements
        
        pair<int, int> l = DAC(root->left);
        pair<int, int> r = DAC(root->right);
        // the calculation below for first:
        // we have "l.first" solutions for the left tree and "r.first" solutions for the right tree
        // to merge the elemenst we have to put "r.second" elements within "l.second" elemenst with the same order in both of them
        // and this can be calculated by nCr(x + y, x), where x and y are the number of elements for each array
        return {1ll * nCr(l.second + r.second, r.second) * l.first % MOD * r.first % MOD, 1 + l.second + r.second};
    }
    
    // Main function to count the number of valid ways to construct the same BST from a given vector of numbers
    int numOfWays(vector<int>& nums) {
        // building Factorial function
        buildFact();
        // constructing BST
        TreeNode *head = new TreeNode(nums.front());
        for (int i = 1; i < nums.size(); i++) {
            insert(nums[i], head);
        }
        // Divide and Conquer
        // substruct one because we count all possible ways including the given array "nums"
        return DAC(head).first - 1;
    }
};
