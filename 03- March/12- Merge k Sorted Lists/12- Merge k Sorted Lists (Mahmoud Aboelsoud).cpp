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
    // we need to merge k sorted lists
    // we can use priority queue to do that
    // in priority queue we need to compare between the lists by the first element in each list
    // so our top element will be the list with the smallest first element among all lists
    // then we add the first element of the top list to the answer list and move to the next element in the top list and push it again to the priority queue
    // we do that until the priority queue is empty


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // we need to compare between the lists by the first element in each list to make the top list in the priority queue the list with the smallest first element among all lists 
        auto comp = [&](ListNode*a, ListNode*b){return a -> val > b -> val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        // push all lists to the priority queue
        for(auto&i: lists)
            if(i != NULL) pq.push(i);

        // create the answer list with the first element 0
        ListNode* ans = new ListNode(0);

        // initialize the current node in the answer list with the first element
        ListNode* cur = ans;

        // while the priority queue is not empty
        while(pq.size()){
            // get the top list in the priority queue
            ListNode* top = pq.top();
            pq.pop();

            // add the first element of the top list to the answer list and move to the next element in the top list
            cur -> next = new ListNode(top -> val);
            top = top -> next;

            // move to the next element in the answer list
            cur = cur -> next;
            // if the top list is not empty push it again to the priority queue
            if(top != NULL) pq.push(top);
        } 

        // return the answer list without the first element 0
        return ans -> next;
    }
};
