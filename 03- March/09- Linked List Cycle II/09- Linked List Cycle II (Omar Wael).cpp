// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

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
    ListNode *detectCycle(ListNode *head) {
        // the idea is to set each visited node to true 
        // and when you find node it's visited value is true 
        // then return it
        ListNode *cur=head;
        unordered_map<ListNode *,bool>vis;
        while(cur!=NULL){
            // check is this node had been visited
            if(vis[cur]){
                return cur;
            }
            // set this node to true 
            vis[cur]=true;
            cur=cur->next;
        }
        return NULL;
    }
};
