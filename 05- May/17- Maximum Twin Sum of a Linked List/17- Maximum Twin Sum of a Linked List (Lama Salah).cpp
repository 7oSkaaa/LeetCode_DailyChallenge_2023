// Author: Lama Salah

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
 
class Solution {
public:
    int pairSum(ListNode* head) {
        // Create a vector to store the values of the linked list nodes.
        vector <int> v;

        // Iterate through the linked list and add each node's value to the vector.
        while (head){
            v.emplace_back(head -> val);
            head = head -> next;
        }

        int l = 0, r = v.size()-1; // Initialize pointers l and r to the start and end of the vector.
        int ans = 0; // Initialize a variable to store the maximum twin sum.

        while (l < r)
            // Calculate the sum of current twin and update the maximum twin sum.
            ans = max(ans, v[l++] + v[r--]);

        // Return the maximum twin sum.
        return ans;
    }
};