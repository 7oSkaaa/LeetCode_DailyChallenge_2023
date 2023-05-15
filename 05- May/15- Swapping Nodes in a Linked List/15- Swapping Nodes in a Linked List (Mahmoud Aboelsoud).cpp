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
    ListNode* swapNodes(ListNode* head, int k) {
        // we need to swap the kth node from the beginning with the kth node from the end
        // we can use a vector to store the values of all nodes
        // then swap the values of the kth node from the beginning with the kth node from the end
        // then update the values of the nodes with the new values

        // v: vector to store the values of all nodes
        vector<int> v;

        // cur: pointer to traverse the linked list
        ListNode* cur = head;

        // loop over the linked list to store the values of all nodes
        while(cur != NULL){
            v.emplace_back(cur -> val);
            cur = cur -> next; 
        }

        // swap the values of the kth node from the beginning with the kth node from the end
        swap(v[k - 1], v[v.size() - k]);
        
        cur = head;

        // loop over the linked list to update the values of the nodes with the new values
        for(auto&i: v){
            cur -> val = i;
            cur = cur -> next;
        }

        // return the head of the linked list
        return head;
        
    }
};
