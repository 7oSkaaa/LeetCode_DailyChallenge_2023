// Author : Ibrahim Khalid
class Solution {
public:
    int pairSum(ListNode* head) {
        // store value
        vector<int>v;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        // two pointers
        int l=0,r=n-1;
        // return the maximum twin sum of the linked list
        int mx=0;
        while(l<r){
            // compare between twin sum  and old max
            mx=max((v[l]+v[r]),mx);
            r--;
            l++;
        }
        return mx;
    }
};
