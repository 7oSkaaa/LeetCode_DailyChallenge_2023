// Author: Ahmed Gamal

// for this problem, we can just use the same logic as of the task that asks us to merge two sorted lists
// at each step, we need to find the minimum value of the heads of the lists and add it to the merged list
// we can do this by using a for loop that checks the heads of the lists and finds the minimum value and stores its index
// then we add the node with the minimum value to the merged list and move the head of the list with the minimum value to the next node
// we can do this until all the lists are empty

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if the lists are empty, then return null
        if(lists.empty())
            return nullptr;

        // create a new list to store the merged list
        auto head = new ListNode();
        auto curr = head;

        // loop until all the lists are empty
        while(true){
            // find the minimum value of the heads of the lists at each step
            // and store its index
            int mn = INT_MAX;
            int tmp = -1;

            // loop over the lists
            for(int i = 0; i < lists.size(); i++){
                // if the list is not empty and the value of the head of the list is less than the minimum value, then update the minimum value and the index of the list with the minimum value
                if(lists[i]){
                    if(lists[i] -> val < mn){
                        mn = lists[i] -> val;
                        tmp = i;
                    }
                }
            }

            // if all the lists are empty, then break the loop
            if(tmp == -1)
                break;

            // add the node with the minimum value to the merged list
            curr -> next = new ListNode(lists[tmp] -> val);

            // move the head of the list with the minimum value to the next node
            lists[tmp] = lists[tmp] -> next;

            // move the current node to the next node
            curr = curr -> next;
        }

        // return the merged list without the dummy node at the beginning
        return head -> next;
    }
};