//Author: Sara Hamza
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
        int n = lists.size();
        // get all values from all lists in one vector
        vector<int>values;
        for(int i = 0; i < n; ++i) {
            ListNode *head = lists[i];
            while(head){
                values.push_back(head->val);
                head = head->next;
            }
        }

        n = values.size();
        if(n == 0)
            return nullptr;
        // sort it
        sort(values.begin(), values.end());

        // build the linked list from the sorted vector
        ListNode *head = new ListNode(values[0]);
        ListNode *prevNode = head;
        for(int i = 1; i < n; ++i) {
            ListNode *node = new ListNode(values[i]);
            prevNode->next = node;
            prevNode = node;
        }
        return head;
    }
};
