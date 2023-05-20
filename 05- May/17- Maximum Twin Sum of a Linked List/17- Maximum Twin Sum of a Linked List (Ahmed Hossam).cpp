// Author: Ahmed Hossam

class Solution {
public:
    
    int pairSum(ListNode* head) {
        // Create a vector to store the values of the linked list nodes
        vector < int > nums;
        ListNode* curr = head;

        // Traverse the linked list and store the values in the vector
        while (curr != nullptr) {
            nums.push_back(curr -> val);
            curr = curr -> next;
        }

        // Initialize left and right pointers, and the maximum sum
        int l = 0, r = nums.size() - 1, mx_sum = INT_MIN;

        // Find the maximum sum of pairs
        while (l < r)
            mx_sum = max(mx_sum, nums[l++] + nums[r--]);

        // Return the maximum sum
        return mx_sum;
    }

};
