//author : Ahmed zedan 
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
    // hash table
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp ; 
        while(head){
            if(mp.count(head)) return head ;  // if node has been visited before , then it is the beginning of the cycle
            else mp[head] = 1 ; 
            head = head->next ; 
        }
        return NULL ; 
    }
};