// Author: Ahmed Hossam

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // initial the current node in the list
        ListNode* root = nullptr;

        // let us save the index of the minimum element of the current head list of lists
        int idx = -1;

        for(int i = 0; i < lists.size(); i++){
            // if the current list is empty skip it
            if(lists[i] == nullptr) continue;

            // if it's the first list we found or it's minimum than the minimum of we found update the index
            if(idx == -1 || lists[i] -> val < lists[idx] -> val)
                idx = i;
        }

        // if there are no lists anymore
        if(idx == -1) return nullptr;

        // update the current node with the minimum value of the minimum node
        root = new ListNode(lists[idx] -> val);

        // move the minimum node to it's next
        lists[idx] = lists[idx] -> next;

        // the next of the current node in the new list will be the returned node of the next step
        root -> next = mergeKLists(lists);

        // return the current node of the new list
        return root;
    }
};
