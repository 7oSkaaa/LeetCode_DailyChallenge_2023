// Author: Ahmed Hossam

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // vector to store the numbers in sorted form
        vector < int > nums;

        // loop over the list and make the numbers sorted
        ListNode* curr = head;
        while(curr != nullptr){
            // add the current number and move to the next number
            nums.push_back(curr -> val);
            curr = curr -> next;
        }

        // the BST Tree
        return construct(0, nums.size() - 1, nums);
    }

    TreeNode* construct(int l, int r, vector < int >& nums){
        // the base if the left pointer greater than right pointer
        if(l > r) return nullptr;
        
        // middle of the current subarray
        int m = l + (r - l) / 2;

        // the middle element will be the root of this subarray
        TreeNode* root = new TreeNode(nums[m]);

        // construct the left subtree with same concept
        root -> left = construct(l, m - 1, nums);

        // construct the right subtree with same concept
        root -> right = construct(m + 1, r, nums);

        // return the root of the current subtree
        return root;
    }
};
