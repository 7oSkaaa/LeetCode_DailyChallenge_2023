// Author: Ahmed Gamal

// for this problem, we can just use a set to store the visited nodes and check if the current node is already visited or not

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // found: set of visited nodes
        // curr: current node in the linked list
        set<ListNode*> found;
        auto curr = head;

        // loop over the linked list
        while(curr){
            // if the current node is already visited, then we have a cycle
            if(found.find(curr) != found.end()){
                return curr;
            }

            // add the current node to the set of visited nodes
            found.emplace(curr);

            // move to the next node
            curr = curr -> next;
        }

        // if we reach here, then there is no cycle
        return nullptr;
    }
};