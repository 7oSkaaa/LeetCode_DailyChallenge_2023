// author : Omar Sanad

/* 
 i    j
[1]->[2]->[3]->[4]->[5]->[6]

Suppose we have this list

we have to swap i and j ...
how to do so?

j->next = i
i->next = the first node of the remaining of the list after doing the swaps

 j    i
[2]->[1]->[the first node of the remaining of the list after doing the swaps]

in this step I will return j


 */
class Solution {
public:

    // recursion function
    ListNode* rec(ListNode* i) {

        // if this node is null or if it's the last node in the list,
        // then we cannot do any swaps, so we return
        if (i == NULL or i->next == NULL)
            return i;

        // we declare two nodes
        // the node adjacent to i, (Which we will swap it with i)
        ListNode *j = i->next;
        // the first node of the remaining of the list
        ListNode *to_go = j->next;

        // swap j and i
        j->next = i;

        // mark the next to i as the first node of the remaining of the list after doing the swaps
        i->next = rec(to_go);

        // return the node j, as now its directly before i
        return j;
    }
    ListNode* swapPairs(ListNode* head) {
        return rec(head);
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
