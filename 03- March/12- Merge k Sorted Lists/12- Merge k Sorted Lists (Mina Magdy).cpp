// Author: Mina Magdy

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /**
         *  @first: value
         *  @second: index of list
         *  @brief: sort every first available node in lists 
         *          by their value then with their index in ascending order
         */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int k = lists.size();
        /** 
         *  if lists[i] NOT NULL:
         *      push it to priority queue {first: value, second: index}
         *      shift lists[i] to the next node
         */
        for (int i = 0; i < k; i++) {
            if (lists[i]) { 
                pq.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        ListNode* root = NULL; // this will be our answer
        ListNode* tail = NULL; // this is the tail to push using it
        while (!pq.empty()) {
            // get the top pair {first: value, second index} {vl, id} and pop it
            auto [vl, id] = pq.top();
            pq.pop();
            /**
             *  if this is the first node to push 
             *  therefore we will store it to the root to NOT be NULL any more
             */ 
            if (!root) {
                root = new ListNode(vl);
                tail = root;
            }
            // if the root NOT NULL (has at least 1 node) then push the current node using tail
            else { 
                tail->next = new ListNode(vl);
                tail = tail->next;
            }
            /** 
             *  if the next lists[id] NOT NULL push it to priority queue
             *  and shift it to the next node
             */
            if (lists[id]) {
                pq.push({lists[id]->val, id});
                lists[id] = lists[id]->next;
            }
        }
        return root;
    }
};
