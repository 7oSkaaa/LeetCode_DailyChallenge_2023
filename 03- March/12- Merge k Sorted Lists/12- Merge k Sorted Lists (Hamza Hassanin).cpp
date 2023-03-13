// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;
/*
    Approach:
        Use merge Sort algorithm to merge each two sorted lists then merge each two Sorted Lists untill we get to one sorted list
        say we have:

                1->2->3
                2->5                1->->2->2->3->5
                            ----->                      ----->  1->2->2->3->4->5->6->7
                3->4->5             3->4->5->6->7
                6->7
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeList(ListNode *one, ListNode *two)
    {
        ListNode *head = new ListNode(-1); // dummy head
        auto cur = head;                   // the pointer when adding nodes
        auto cur1 = one;                   // the head of the first lists
        auto cur2 = two;                   // the head of the second lists

        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                cur->next = cur1;
                cur1 = cur1->next;
                cur->next->next = nullptr;
            }
            else
            {
                cur->next = cur2;
                cur2 = cur2->next;
                cur->next->next = nullptr;
            }
            cur = cur->next;
        }
        // if we end the loop then one if cur1 or cur2 must be null or both of them are null
        cur->next = cur1 ? cur1 : cur2;

        return head->next;
    }
    ListNode *mergeSort(int left, int right, vector<ListNode *> &lists)
    {
        if (right <= left) // if we are staning on the same node from left and right or the left is greater than right then return the left node
            return lists[left];
        int mid = left + (right - left) / 2;
        auto list1 = mergeSort(left, mid, lists);      // divide the left part
        auto list2 = mergeSort(mid + 1, right, lists); // divide the right part

        return mergeList(list1, list2); // merge the sorted left and right
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (!k) // if there are no nodes in the lists array return null
            return nullptr;

        return mergeSort(0, k - 1, lists); // get our merged and sorted lists
    }
};

/*


    1 2 3 4 5
    2 4 6
    1 7 8 9


*/