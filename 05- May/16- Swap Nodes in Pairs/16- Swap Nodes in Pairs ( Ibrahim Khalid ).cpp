// Author : Ibrahim Khalid
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // to store values
        vector<int>v;

        ListNode* temp=head;
         // move between values in linkedlist and store it in vector
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        // swap every two adjacent elements in vector
        for(int i=0;i<n;i+=2){
            if(i+1<n){
            swap(v[i],v[i+1]);
            }
        }
        // reorder linkedlist by modified vector
        ListNode* tmp=head;
        int in=0;
        while(tmp!=NULL){
            tmp->val=v[in];
            tmp=tmp->next;
            in++;
        }

        return head;
    }
};
