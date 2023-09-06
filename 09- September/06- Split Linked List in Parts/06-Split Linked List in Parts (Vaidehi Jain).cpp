// Author: Vaidehi Jain

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        vector<ListNode*>v(k,NULL);
        int p=len/k;
        int extra=len%k;
        temp=head;
        int j=0;
        while(temp!=NULL){
            ListNode*c=temp;
            ListNode*temp1=new ListNode(-1);
            ListNode*curr=temp1;
            for(int i=0;i<p;i++){
                curr->next=new ListNode(temp->val);
                temp=temp->next;
                curr=curr->next;
            }
            if(extra>0){
                curr->next=new ListNode(temp->val);
                temp=temp->next;
                curr=curr->next;
                extra--;
            }
            v[j]=temp1->next;
            j++;
        }
        return v;
    }
};
