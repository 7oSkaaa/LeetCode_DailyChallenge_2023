// Author : Ibarhim Khalid
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // to store values
        vector<int>v;
        int cnt=0;
        ListNode *temp = head;
        // move between values in linkedlist and store it in vector
        while(temp !=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        // swapping the values of the kth node from the beginning and the kth node from the end
        swap(v[k-1],v[v.size()-k]);
        // pointer to index in vector
        int in=0;
        ListNode *tmp = head;
        // reorder linkedlist by modified vector
         while(tmp !=NULL){
            tmp->val=v[in];
            cout<<tmp->val<<" ";
            tmp=tmp->next;
            in++;
        }

        return head;
    }
};
