// author : Omar Sanad

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // declare two Nodes one pointing to k_th node from the beginning
        // the other pointing to k_th node from the end
        ListNode *FRONT, *BACK;

        // initialize a variable sz to store the length of the linked list
        int sz = 0;

        // intialize a variable "curr" to keep track the of the curr node while calculating the length of the linked list
        ListNode* curr = head;
        while (curr != NULL)
            curr = curr->next, sz++;
        
        // initialize a variable "i" to keep track of the idx of the current node .....
        // while trying to select the k_th node from the beginning and the k_th node from the end
        int i = 1;
        
        // update the value of curr to reuse it again while iterating over the linked list
        curr = head;

        // iterate over the linked list to select the k_th from beginning and the k_th from end
        while (curr != NULL) {
            
            // if the current idx == k, then this is the k_th from beginning
            if (i == k)
                FRONT = curr;

            // if the current idx == sz - k + 1, then this is the k_th from the end
            if (i == sz - k + 1)
                BACK = curr;
            
            // every iteration we update the curr and i
            curr = curr->next;
            i++;
        }

        // swap the values of the two nodes
        swap(FRONT->val, BACK->val);

        // return the given list after modifing if
        return head;
    }
};

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
