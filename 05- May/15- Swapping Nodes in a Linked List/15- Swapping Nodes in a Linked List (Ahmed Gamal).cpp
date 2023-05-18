// Author: Ahmed Gamal

// this is a simple implementation problem
// we will use two pointers to point to the kth from the beginning and the kth from the end
// then we will swap them
// to get the kth from the end, we will use the size of the list - k + 1
// to get the size of the list, we will iterate over the list and count the number of nodes

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
        // size: the size of the list
        // i: the kth node from the beginning
        // j: the kth node from the end
        int size = 0;
        ListNode *i;
        auto j = head;

        // we will iterate over the list and count the number of nodes
        while(j) {
            size++;

            // if we reached the kth node from the beginning, we will save it in i
            if(size == k) {
                i = j;
            }
            j = j -> next;
        }

        // we will get the kth node from the end (size - k + 1)
        size -= k;
        j = head;
        while(size--) {
            j = j -> next;
        }

        // we will swap the values of the two nodes
        swap(i -> val, j -> val);

        // we will return the head of the list
        return head;
    }
};