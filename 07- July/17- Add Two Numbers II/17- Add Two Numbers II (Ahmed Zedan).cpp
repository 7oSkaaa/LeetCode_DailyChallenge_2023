// author : Ahmed Zedan
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int> s1 , s2 ;  // use stack (s1) to revese list (l1) and use stack (s2) to reverse list (l2) 

        while(l1){
            s1.push(l1->val) ; 
            l1 = l1->next ; 
        }

        while(l2){
            s2.push(l2->val) ; 
            l2 = l2->next ; 
        }


        ListNode *head  = NULL;  // answer list 

        int carry = 0 ;   

        while(s1.size() && s2.size()){
            int x = s1.top() , y = s2.top() , z = x+y+carry; 
            ListNode *tmp = new ListNode( z%10 , head) ; 
            head = tmp ; 
            carry = (z>9 ? 1 : 0) ; 
            s1.pop() ; 
            s2.pop() ;
        }

        if(s1.size()<s2.size()) s1 = s2 ; 

        while(s1.size()){
            int x = s1.top() ; 
            x+=carry ; 
            ListNode *tmp = new ListNode( x%10 , head) ;
            head = tmp ; 
            carry = (x>9 ? 1 : 0) ; 
            s1.pop() ; 
        }


        if(carry){
            ListNode *tmp = new ListNode( 1 , head) ;
            head = tmp ; 
        }


        return head ;  
    }
};