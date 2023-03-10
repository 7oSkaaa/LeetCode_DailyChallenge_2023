// Author: Mahmoud Aboelsoud

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
    // store the values of the linked list in a vector
    // return a random value from the vector

    // vector to store the values of the linked list
    vector<int> v;
    Solution(ListNode* head) {
        // loop through the linked list and store the values in the vector
        while(head != NULL){
            v.push_back(head -> val);
            head = head -> next;
        }
    }
    
    int getRandom() {
        // return a random value from the vector
        // rand() % v.size() returns a random number between 0 and v.size() - 1
        return v[rand() % v.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
