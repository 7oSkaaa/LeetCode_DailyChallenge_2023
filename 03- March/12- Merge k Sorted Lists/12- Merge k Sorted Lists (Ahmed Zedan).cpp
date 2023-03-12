//author : Ahmed Zedan 
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
        priority_queue<int,vector<int>,greater<int>>nums ; // sort values in non-decreasing order by priority queue 
        for(auto head : lists){
            while(head){
                nums.push(head->val) ; 
                head = head->next ; 
            }
        }
        if(nums.empty()) return nullptr ;  // if all lists empty return nullptr
        // Merge all the linked-lists into one sorted linked-list
        ListNode* head = new ListNode(nums.top()); 
        nums.pop() ; 
        ListNode* tmp = head ; 

        while(!nums.empty()){
            ListNode* newnode = new ListNode(nums.top()) ;
            nums.pop() ;  
            tmp->next = newnode ; 
            tmp = newnode ; 
        }

        return head ; 
    }
};